#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - prints a formatted string to standard output
 * @format: format string containing directives
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    char c;
    char *str;
    int count = 0, num;
    int is_negative = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                    c = va_arg(args, int);
                    write(1, &c, 1);
                    count++;
                    break;
                case 's':
                    str = va_arg(args, char *);
                    while (*str)
                    {
                        write(1, str, 1);
                        str++;
                        count++;
                    }
                    break;
                case 'd':
                case 'i':
                    num = va_arg(args, int);
                    if (num < 0)
                    {
                        is_negative = 1;
                        num = -num;
                    }
                    if (num == 0)
                    {
                        write(1, "0", 1);
                        count++;
                    }
                    while (num > 0)
                    {
                        char digit = (num % 10) + '0';
                        write(1, &digit, 1);
                        count++;
                        num /= 10;
                    }
                    if (is_negative)
                    {
                        write(1, "-", 1);
                        count++;
                        is_negative = 0;
                    }
                    break;
                case '%':
                    write(1, "%", 1);
                    count++;
                    break;
                default:
                    break;
            }
        }
        else
        {
            write(1, format, 1);
            count++;
        }
        format++;
    }

    va_end(args);

    return count;
}
