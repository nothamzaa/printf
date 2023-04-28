#include "main.h"

/**
 * Checks if a character is printable.
 *
 * @param c The character to check.
 * @return 1 if c is printable, 0 otherwise.
 */
int is_printable(char c)
{
    if (c >= 32 && c < 127)
        return 1;
    return 0;
}

/**
 * Appends ASCII in hexadecimal code to a buffer.
 *
 * @param buffer The array of characters to append to.
 * @param i The index at which to start appending.
 * @param ascii_code The ASCII code to append.
 * @return Always returns 3.
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
    char map_to[] = "0123456789ABCDEF";
    if (ascii_code < 0)
        ascii_code *= -1;

    buffer[i++] = '\\';
    buffer[i++] = 'x';

    buffer[i++] = map_to[ascii_code / 16];
    buffer[i] = map_to[ascii_code % 16];

    return 3;
}

/**
 * Checks if a character is a digit.
 *
 * @param c The character to check.
 * @return 1 if c is a digit, 0 otherwise.
 */
int is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

/**
 * Casts a number to the specified size.
 *
 * @param num The number to be casted.
 * @param size The size to cast to.
 * @return The casted value of num.
 */
long int convert_size_number(long int num, int size)
{
    if (size == S_LONG)
        return num;
    else if (size == S_SHORT)
        return (short)num;
    return (int)num;
}

/**
 * Casts an unsigned number to the specified size.
 *
 * @param num The number to be casted.
 * @param size The size to cast to.
 * @return The casted value of num.
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
    if (size == S_LONG)
        return num;
    else if (size == S_SHORT)
        return (unsigned short)num;
    return (unsigned int)num;
}
