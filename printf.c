#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: the format string
 * Return: the number of characters printed (excluding null
 * used to end output string)
 */

/*main printf function*/
int _printf(const char *format, ...)
{
	int i = 0, count = 0;

	va_list args;
	char c, *s;

	va_start(args, format);

	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					c = va_arg(args, int);
					count += print_char(c);
					break;
				case 's':
					s = va_arg(args, char *);
					count += print_string(s);
					break;
				case '%':
					count += print_char('%');
					break;
				default:
					count += print_char('%');
					count += print_char(format[i]);
					break;
			}
		}
		else
		{
			count += print_char(format[i]);
		}
	}
	va_end(args);
	return (count);
}

/**
 * print_char - prints a single character
 * @c: the character to print
 * Return: the number of characters pinted (always 1)
 */

/*helper function to print a single character*/
int print_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - prints a string
 * @str: the string to print
 * Return: the number of characterss printed
 */
int print_string(char *str)
{
	int i;

	if (str == NULL)
		str = "(null)"; /*handle null string*/
	/*iterate through the string and print each character*/
	for (i = 0; str[i]; i++)
	{
		print_char(str[i]);
	}
	return (1);
}
