#include <unistd.h>
#include <stdlib.h>

/**
 * print_number - Prints an integer.
 * @num: The integer to print.
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

