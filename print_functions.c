#include "main.h"

/**
 * print_char - Prints a char
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * 
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);
	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/**
 * print_string - Prints a string
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * 
 * Return: Number of chars printed
 */
int print_string(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);
	
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	
	if (str == NULL)
	{
		str = "(null)";
	}
	
	while (str[length] != '\0')
	{
		length++;
	}
	
	if (precision >= 0 && precision < length)
	{
		length = precision;
	}
	
	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, str, length);
			for (i = width - length; i > 0; i--)
			{
				write(1, " ", 1);
			}
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
			{
				write(1, " ", 1);
			}
			write(1, str, length);
			return (width);
		}
	}
	
	return (write(1, str, length));
}

/**
 * print_percent - Prints a percent sign
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * 
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	
	return (write(1, "%%", 1));
}

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
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;
	
	n = convert_size_number(n, size);
	
	if (n == 0)
	{
		buffer[i--] = '0';
	}
	
	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;
	
	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}
	
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	
	i++;
	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/**
 * print_binary - Prints an unsigned number in binary
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * 
 * Return: Number of chars printed
 */
int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	unsigned int n = va_arg(types, unsigned int);
	unsigned int a[32];
	int i, count = 0;
	
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	
	for (i = 0; i < 32; i++)
	{
		a[i] = n >> (31 - i) & 1;
		if (a[i])
		{
			count++;
			write(1, &"01"[a[i]], 1);
		}
	}
	
	if (count == 0)
	{
		write(1, "0", 1);
		count = 1;
	}
	
	return (count);
}
