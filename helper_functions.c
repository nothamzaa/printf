#include "main.h"

int print_char(char c)
{
    return (write(1, &c, 1));
}

int print_string(char *str)
{
    int i = 0;

    while (str[i])
        i += print_char(str[i]);

    return (i);
}

int print_number(int n)
{
    unsigned int num = n;
    int digits = 0;

    if (n < 0)
    {
        num = -num;
        print_char('-');
    }

    if (num / 10)
        digits += print_number(num / 10);

    digits += print_char((num % 10) + '0');

    return (digits);
}
