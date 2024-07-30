#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * print_char - prints a character
 * @args: list of arguments
 * Return: number of characters printed
 */

int print_char(va_list args)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	return (1);
}

/**
 * print_string - prints a string
 * @args: list of arguments
 * Return: number of characters
 */

int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	while (*str)
	{
		write(1, str++, 1);
		count++;
	}
	return (count);
}

/**
 * print_percent - print a percent sign
 * @args: list of arguments (unused)
 * Return: numbers of characters printed
 */

int print_percent(__attribute__((unused)) va_list args)
{
	write(1, "%", 1);
	return (1);
}

/**
 * _printf - produces output according to a format
 * @format: a character string
 * Return: the number o characters printed (excl null byte)
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int i;

	va_start(args, format);

	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					count += print_char(args);
					break;
				case 's':
					count += print_string(args);
					break;
				case '%':
					count += print_percent(args);
					break;
				default:
					write(1, &format[i], 1);
					count++;
					break;
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
	}

	va_end(args);
	return (count);
}
