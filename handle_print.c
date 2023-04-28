#include "main.h"

/**
 * handle_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @ind: Pointer to the index of the current format specifier in the format string.
 * @list: List of arguments to be printed.
 * @buffer: Buffer array to handle print.
 * @flags: Bitmask of active flags.
 * @width: Field width specifier.
 * @precision: Precision specifier.
 * @size: Size specifier.
 *
 * Return: The number of characters written on success, -1 on failure.
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
                 int flags, int width, int precision, int size)
{
    static const struct {
        char fmt;
        int (*fn)(va_list, char *, int, int, int, int);
    } fmt_types[] = {
        {'c', print_char},
        {'s', print_string},
        {'%', print_percent},
        {'i', print_int},
        {'d', print_int},
        {'b', print_binary},
        {'u', print_unsigned},
        {'o', print_octal},
        {'x', print_hexadecimal},
        {'X', print_hexa_upper},
        {'p', print_pointer},
        {'S', print_non_printable},
        {'r', print_reverse},
        {'R', print_rot13string},
        {'\0', NULL}
    };
    int i, unknown_len = 0, printed_chars = -1;
    char curr_fmt = fmt[*ind];

    for (i = 0; fmt_types[i].fmt != '\0'; i++) {
        if (curr_fmt == fmt_types[i].fmt) {
            return fmt_types[i].fn(list, buffer, flags, width, precision, size);
        }
    }

    if (curr_fmt == '\0') {
        // End of format string.
        return -1;
    }

    // Unknown format specifier.
    if (fmt[*ind - 1] == ' ') {
        unknown_len += write(1, " ", 1);
    } else if (width > 0) {
        // Field width specified but format unknown.
        while (*ind > 0 && fmt[*ind] != ' ' && fmt[*ind] != '%') {
            (*ind)--;
        }
        if (fmt[*ind] == ' ') {
            (*ind)--;
        }
        return 1;
    }

    unknown_len += write(1, &curr_fmt, 1);
    return unknown_len;
}
