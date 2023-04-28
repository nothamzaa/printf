#include "main.h"

/**
 * print_char - prints a char
 * @args: va_list containing the character to print
 * Return: number of characters printed
 */
int print_char(va_list args)
{
        char c = va_arg(args, int);
        return (_putchar(c));
}

/**
 * print_string - prints a string
 * @args: va_list containing the string to print
 * Return: number of characters printed
 */
int print_string(va_list args)
{
        char *str = va_arg(args, char *);
        int i = 0;

        if (!str)
                str = "(null)";

        while (str[i])
        {
                _putchar(str[i]);
                i++;
        }
        return (i);
}

/**
 * print_percent - prints a percent sign
 * @args: va_list (unused)
 * Return: number of characters printed
 */
int print_percent(va_list args)
{
        (void)args;
        return (_putchar('%'));
}

/**
 * print_int - prints an integer
 * @args: va_list containing the integer to print
 * Return: number of characters printed
 */
int print_int(va_list args)
{
        int num = va_arg(args, int);
        int num_cpy = num;
        int num_digits = 0, i = 0, j = 0;
        char num_arr[1024];

        if (num == 0)
                return (_putchar('0'));
        if (num < 0)
        {
                num_cpy = -num;
                _putchar('-');
                i++;
        }
        while (num_cpy != 0)
        {
                num_arr[i] = num_cpy % 10 + '0';
                num_cpy /= 10;
                i++;
                num_digits++;
        }
        for (j = num_digits - 
