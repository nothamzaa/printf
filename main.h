#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list args);
int print_str(va_list args);
int print_percent(va_list args);
int print_binary(va_list args);
int get_binary_len(unsigned int n);

/**
 * struct print_fmt - struct to match format specifier with printing function
 * @fmt: the format specifier
 * @printer: the function that handles the specifier
 *
 * Description: used to match the format specifier to the printing function.
 * E.g. the format specifier 'c' should use the print_char() function
 */
typedef struct print_fmt
{
    char fmt;
    int (*printer)(va_list);
} print_fmt_t;

#endif /* MAIN_H */
