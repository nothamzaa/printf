#include "main.h"

// Declare function prototypes
void print_buffer(char buffer[], int* buff_ind);

/**
 * _printf - Custom printf function that supports formatting options
 * @format: A string containing the format specifier and optional arguments
 * @...: Optional arguments to be printed, corresponding to the format specifier
 * Return: The total number of characters printed
 */
int _printf(const char* format, ...)
{
    // Initialize variables and buffer
    int printed_chars = 0, buff_ind = 0;
    char buffer[BUFF_SIZE] = { 0 };

    // Check if format is NULL
    if (format == NULL)
        return -1;

    // Initialize argument list
    va_list arg_list;
    va_start(arg_list, format);

    // Loop through each character in format
    for (int i = 0; format[i] != '\0'; i++)
    {
        // Check if current character is a format specifier
        if (format[i] == '%')
        {
            // Print the contents of the buffer
            print_buffer(buffer, &buff_ind);

            // Parse the format specifier and print the corresponding value
            int printed = handle_print(format, &i, arg_list, buffer);
            if (printed == -1)
            {
                va_end(arg_list);
                return -1;
            }

            // Update the total number of printed characters
            printed_chars += printed;
        }
        else
        {
            // Add the current character to the buffer
            buffer[buff_ind++] = format[i];

            // If the buffer is full, print its contents
            if (buff_ind == BUFF_SIZE)
                print_buffer(buffer, &buff_ind);

            // Update the total number of printed characters
            printed_chars++;
        }
    }

    // Print any remaining characters in the buffer
    print_buffer(buffer, &buff_ind);

    // Clean up and return the total number of printed characters
    va_end(arg_list);
    return printed_chars;
}

/**
 * print_buffer - Prints the contents of the buffer if it is not empty
 * @buffer: An array of characters representing the buffer
 * @buff_ind: A pointer to the index of the next empty position in the buffer
 */
void print_buffer(char buffer[], int* buff_ind)
{
    if (*buff_ind > 0)
        write(1, buffer, *buff_ind);

    // Reset the buffer index to zero
    *buff_ind = 0;
}
