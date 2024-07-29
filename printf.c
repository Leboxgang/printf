#include "main.h"
#include <unistd.h>

/**
 * _printf - Produces output according to a format
 * @format: The format string
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;
    char c;
    char *s;

    if (!format)
    {
        return (-1);
    }

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%' && format[i + 1] != '\0')
        {
            i++;

            switch (format[i])
            {
                case 'c':
                    c = (char) va_arg(args, int);
                    write(1, &c, 1);
                    count++;
                    break;

                case 's':
                    s = va_arg(args, char *);
                    if (s)
                    {
                        while (*s)
                        {
                            write(1, s++, 1);
                            count++;
                        }
                    }
                    else
                    {
                        write(1, "(null)", 6);
                        count += 6;
                    }
                    break;

                case '%':
                    write(1, "%", 1);
                    count++;
                    break;

                default:
                    write(1, "%", 1);
                    write(1, &format[i], 1);
                    count += 2;
                    break;
            }
        }
        else
        {
            write(1, &format[i], 1);
            count++;
        }

        i++;
    }

    va_end(args);

    return (count);
}
/**
 * task 2 
 * print_number - Helper function to print integer numbers
 * @num: The integer number to print
 *
 * Return: The number of characters printed
 */
int print_number(int num)
{
    char buffer[11];
    int i = 0, len = 0;

    if (num == 0)
    {
        write(1, "0", 1);
        return (1);
    }

    while (num != 0)
    {
        buffer[i++] = (num % 10) + '0';
        num /= 10;
    }

    while (i > 0)
    {
        write(1, &buffer[--i], 1);
        len++;
    }

    return (len);
}
