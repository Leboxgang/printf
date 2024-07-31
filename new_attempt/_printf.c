#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 * @...: The values to format and print.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	convert p[] =
	{
		{"%c", print_c},
		{"%s", print_s},
		{"%%", print_37}
	};

	va_list args;
	int i = 0, j, length = 0;

	va_start(args, format);
	if (format == NULL)
		return (-1);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			j = 0;
			while (j < 3)
			{
				if (format[i + 1] == p[j].ph[1] && format[i] == p[j].ph[0])
				{
					length += p[j].function(args);
					i += 2;
					break;
				}
				j++;
			}
			if (j == 3)
			{
				_putchar(format[i]);
				length++;
				i++;
			}
		}
		else
		{
			_putchar(format[i]);
			length++;
			i++;
		}
	}

	va_end(args);
	return (length);
}
