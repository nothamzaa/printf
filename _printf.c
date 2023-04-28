#include "main.h"

/**
 * _printf - produces output according to a format.
 * @format: character string.
 * Return: the number of characters printed (excluding the null byte used to
 * end output to strings)
 */
int _printf(const char *format, ...)
{
        va_list args;
        int i = 0, printed_chars = 0;

        if (!format)
                return (-1);

        va_start(args, format);

        while (format[i])
        {
                if (format[i] == '%')
                {
                        i++;
                        if (format[i] == '\0')
                                return (-1);
                        while (format[i] == ' ')
                                i++;
                        if (format[i] == '%')
                                printed_chars += print_percent(args);
                        else if (format[i] == 'c')
                                printed_chars += print_char(args);
                        else if (format[i] == 's')
                                printed_chars += print_string(args);
                        else if (format[i] == 'd' || format[i] == 'i')
                                printed_chars += print_int(args);
                        else
                        {
                                printed_chars += _putchar('%');
                                printed_chars += _putchar(format[i]);
                        }
                }
                else
                        printed_chars += _putchar(format[i]);
                i++;
        }
        va_end(args);
        return (printed_chars);
}
