#include "main.h"
#include <stdlib.h>

int _printf(const char *format, ...)
{
    int printed_chars = 0;
    va_list arg;
    char *str;

    va_start(arg, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                    printed_chars += print_char(va_arg(arg, int));
                    break;
                case 's':
                    str = va_arg(arg, char *);
                    if (!str)
                        str = "(null)";
                    printed_chars += print_string(str);
                    break;
                case '%':
                    printed_chars += print_char('%');
                    break;
                case 'd':
                case 'i':
                    printed_chars += print_number(va_arg(arg, int));
                    break;
                default:
                    printed_chars += print_char('%');
                    printed_chars += print_char(*format);
                    break;
            }
        }
        else
            printed_chars += print_char(*format);
        format++;
    }
    va_end(arg);

    return (printed_chars);
}
