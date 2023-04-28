#include "main.h"

/**
 * print_pointer - Prints the value of a pointer variable
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width specifier
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_pointer(va_list types, char buffer[],
                 int flags, int width, int precision, int size)
{
    const char *hex_digits = "0123456789abcdef";
    char extra_c = 0, padd = ' ';
    int ind = BUFF_SIZE - 2, length = 2;
    unsigned long num_addrs;
    void *addrs = va_arg(types, void *);

    UNUSED(size);

    if (addrs == NULL)
        return (write(1, "(nil)", 5));

    buffer[BUFF_SIZE - 1] = '\0';
    UNUSED(precision);

    num_addrs = (unsigned long)addrs;

    while (num_addrs > 0)
    {
        buffer[ind--] = hex_digits[num_addrs % 16];
        num_addrs /= 16;
        length++;
    }

    if ((flags & F_ZERO) && !(flags & F_MINUS))
        padd = '0';
    if (flags & (F_PLUS | F_SPACE))
        extra_c = (flags & F_PLUS) ? '+' : ' ', length++;

    ind++;

    return (write_pointer(buffer, ind, length, width, padd, extra_c));
}

/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width specifier
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_non_printable(va_list types, char buffer[],
                        int flags, int width, int precision, int size)
{
    int i = 0, offset = 0;
    const char *hex_digits = "0123456789abcdef";
    char *str = va_arg(types, char *);

    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

    if (str == NULL)
        return (write(1, "(null)", 6));

    while (str[i] != '\0')
    {
        if (is_printable(str[i]))
            buffer[i + offset] = str[i];
        else
        {
            buffer[i + offset++] = '\\';
            buffer[i + offset++] = 'x';
            buffer[i + offset++] = hex_digits[(str[i] >> 4) & 0xf];
            buffer[i + offset] = hex_digits[str[i] & 0xf];
        }
        i++;
    }

    buffer[i + offset] = '\0';

    return (write(1, buffer, i + offset));
}

/**
 * print_reverse - Prints reverse string.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width specifier
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int print_reverse(va_list types, char buffer[],
                  int flags, int width, int precision, int size)
{
    char *str;
    int i, count = 0;

    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(size);

    str = va_arg(types, char *);

    if (str ==
