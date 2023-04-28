#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _print_char - prints a character
 * @arg: list containing a single character to print
 *
 * Return: the number of characters printed
 */
int _print_char(va_list arg)
{
	char c = va_arg(arg, int);
	_putchar(c);
	return (1);
}

/**
 * _print_string - prints a string
 * @arg: list containing a string to print
 *
 * Return: the number of characters printed
 */
int _print_string(va_list arg)
{
	char *str = va_arg(arg, char *);
	int count = 0;

	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		_putchar(*str);
		count++;
		str++;
	}
	return (count);
}

/**
 * _print_percent - prints a percent sign
 * @arg: unused
 *
 * Return: the number of characters printed
 */
int _print_percent(__attribute__((unused)) va_list arg)
{
	_putchar('%');
	return (1);
}

/**
 * _print_binary - prints an unsigned int in binary form
 * @arg: list containing an unsigned int to print
 *
 * Return: the number of characters printed
 */
int _print_binary(va_list arg)
{
	unsigned int num = va_arg(arg, unsigned int);
	int count = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	else if (num == 1)
	{
		_putchar('1');
		return (1);
	}

	while (num)
	{
		_putchar((num & 1) + '0');
		num >>= 1;
		count++;
	}
	return (count);
}

/**
 * _printf - prints output according to a format
 * @format: list of zero or more directives
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list arg;
	int count = 0;

	va_start(arg, format);
	while (format && *format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'c':
				count += _print_char(arg);
				break;
			case 's':
				count += _print_string(arg);
				break;
			case '%':
				count += _print_percent(arg);
				break;
			case 'b':
				count += _print_binary(arg);
				break;
			default:
				_putchar('%');
				_putchar(*format);
				count += 2;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(arg);
	return (count);
}
