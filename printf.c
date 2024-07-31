#include <stdarg.h>
#include <unistd.h>
#include "main.h"
#include <stdlib.h>

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
/**
 * print_number - Helper function to print integer numbers
 * @num: The integer number to print
 *
 * Return: The number of characters printer
 */
char *int_to_str(int num)
{
	char *str;
	int len = 0, temp = num;
	unsigned int n;

	if (num == 0)
	{
		str = malloc(2);
		if (!str)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (num < 0)
	{
		len++;
		n = num;
	}
	else
	{
		n = num;
	}
	while (temp != 0)
	{
		temp /= 10;
		len++;
	}

	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';

	while (n != 0)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	if (num < 0)
	{
		str[0] = '-';
	}

	return (str);
}

/**
 * print_number - Prints an integer to stdout
 * @num: The integer to print
 *
 * Return: The number of characters printed.
 */
int print_number(int num)
{
	char *str = int_to_str(num);
	int len = 0;

	if (str)
	{
		while (str[len])
		{
			write(1, &str[len], 1);
			len++;
		}
		free(str);
	}
	return (len);
}
