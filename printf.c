#include "main.h"
#include <unistd.h>
#include <stdarg.h>

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
