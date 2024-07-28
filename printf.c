#include "main.h"

#define BUFF_SIZE 1024

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format string.
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	int i, printed_chars = 0, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			i++;
			switch (format[i])
			{
				case 'c':
					buffer[buff_ind++] = (char)va_arg(list, int);
					if (buff_ind == BUFF_SIZE)
						print_buffer(buffer, &buff_ind);
					printed_chars++;
					break;
				case 's':
				{
					char *str = va_arg(list, char *);
					int j;

					if (str == NULL)
						str = "(null)";
					for (j = 0; str[j] != '\0'; j++)
					{
						buffer[buff_ind++] = str[j];
						if (buff_ind == BUFF_SIZE)
							print_buffer(buffer, &buff_ind);
						printed_chars++;
					}
					break;
				}
				case '%':
					buffer[buff_ind++] = '%';
					if (buff_ind == BUFF_SIZE)
						print_buffer(buffer, &buff_ind);
					printed_chars++;
					break;
				default:
					buffer[buff_ind++] = '%';
					if (buff_ind == BUFF_SIZE)
						print_buffer(buffer, &buff_ind);
					buffer[buff_ind++] = format[i];
					if (buff_ind == BUFF_SIZE)
						print_buffer(buffer, &buff_ind);
					printed_chars += 2;
					break;
			}
		}
	}

	print_buffer(buffer, &buff_ind);
	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
