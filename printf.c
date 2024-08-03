#include "main.h"
#include <stdio.h>

/**
 * _printf - produces output according to a format.
 * @format: a character string containing the format directives
 * Return: the number of characters printed (exclu Null byte)
 * used to end utput to strings
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i, count = 0;
	char c, *s;

	va_start(args, format);

	/*iterate through the format string*/
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++; /*move to the next character*/
			switch (format[i])
			{
				case 'c':
					c = va_arg(args, int); /*get char arg*/
					count += print_char(c);
					break;
				case 's':
					s = va_arg(args, char *); /*print str*/
					count += print_string(s);
					break;
				case '%':
					/*print '%' and unknwn specifiier*/
					count += print_char('%');
					count += print_char(format[i]);
					break;
			}
		}
		else
		{
			count += print_char(format[i]); /*print reg chars*/
		}
	}
	va_end(args);
	return (count);
}

/**
 * print_string - Prints a string.
 * @str: The string to print.
 *
 * Return: The number of characters printed.
 */
int print_string(char *str)
{
	int i, count = 0;

	if (str == NULL)
		str = "(null)"; /*handle null str*/

	/*iterate through the stirng and pring each character*/
	for (i = 0; str[i]; i++)
	{
		count += print_char(str[i]);
	}
	return (count);
}

/**
 * print_char - Prints a single character.
 * @c: The character to print.
 *
 * Return: The number of characters printed (always 1).
 */

int print_char(char c)
{
	return (write(1, &c, 1));
}
