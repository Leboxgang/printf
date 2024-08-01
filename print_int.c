#include "main.h"

/**
 * print_int - Print an integer
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * 
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int n = va_arg(types, int);
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	unsigned int num;
	
	if (n == 0)
	{
		buffer[i--] = '0';
	}

	buffer[BUFF_SIZE - 1] = '\0';

	if (n < 0)
	{
		is_negative = 1;
		num = -n;
	}
	else
	{
		num = n;
	}
	
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	
	if (is_negative)
	{
		buffer[i--] = '-';
	}
	
	i++;
	
	return (write(1, &buffer[i], BUFF_SIZE - 1 - i));
}

/**
 * _printf - A simplified printf function
 * @format: The format string
 * 
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	int i = 0;
	char buffer[BUFF_SIZE];
	
	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		{
			printed_chars += print_int(args, buffer, 0, 0, 0, 0);
			i += 2;
		}
		else
		{
			write(1, &format[i], 1);
			printed_chars++;
			
			i++;
		}
	}
	
	va_end(args);
	return (printed_chars);
}
