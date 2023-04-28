#include "main.h"

/**
 * print_char - Prints a single character to the standard output.
 * @c: The character to print.
 *
 * Return: The number of characters printed (always 1).
 */
int print_char(char c)
{
    return (write(1, &c, 1));
}

/**
 * print_string - Prints a string of characters to the standard output.
 * @str: A pointer to the string to print.
 *
 * Return: The number of characters printed.
 */
int print_string(char *str)
{
    int len = 0;

    while (str[len] != '\0')
        len++;

    return (write(1, str, len));
}

/**
 * print_number - Prints an integer to the standard output.
 * @n: The integer to print.
 *
 * Return: The number of characters printed.
 */
int print_number(int n)
{
    /* TODO: Implement the print_number() function */
    return (0);
}
