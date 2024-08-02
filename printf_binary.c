#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/* Prototype for the custom _printf function */
int _printf(const char *format, ...);

/* Helper functions */
char *uint_to_binary(unsigned int num);
char *custom_strdup(const char *str);

int main(void)
{
	_printf("Binary of %u is %b\n", 5, 5);
	return (0);
}

/**
 * _printf - Custom printf function to handle %b conversion specifier
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *p;
	unsigned int num;
	char *binary;

	va_start(args, format);

	for (p = format; *p != '\0'; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == 'b')
			{
				num = va_arg(args, unsigned int);
				binary = uint_to_binary(num);
				if (binary != NULL)
				{
					for (int i = 0; binary[i] != '\0'; i++, count++)
					{
						putchar(binary[i]);
					}
					free(binary);
				}
				continue;
			}
			else
			{
				putchar('%');
				putchar(*p);
				count += 2;
				continue;
			}
		}
		putchar(*p);
		count++;
	}

	va_end(args);
	return (count);
}

/**
 * uint_to_binary - Convert an unsigned int to a binary string
 * @num: the unsigned int to convert
 *
 * Return: pointer to the binary string, must be freed by the caller
 */
char *uint_to_binary(unsigned int num)
{
	char *binary;
	int i, len = sizeof(unsigned int) * 8;

	binary = malloc(len + 1);
	if (binary == NULL)
		return (NULL);

	for (i = len - 1; i >= 0; i--)
	{
		binary[i] = (num & 1) ? '1' : '0';
		num >>= 1;
	}
	binary[len] = '\0';

	/* Remove leading zeros */
	i = 0;
	while (binary[i] == '0' && binary[i + 1] != '\0')
		i++;

	char *result = custom_strdup(&binary[i]);
	free(binary);

	return (result);
}

/**
 * custom_strdup - Custom implementation of strdup function
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string, must be freed by the caller
 */
char *custom_strdup(const char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;


	char *dup = malloc(len + 1);
	if (dup == NULL)

		return (NULL);

	for (int i = 0; i <= len; i++)
		dup[i] = str[i];

	return (dup);
}
