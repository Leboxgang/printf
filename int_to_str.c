#include <stdlib.h>

/**
 * int_to_str - Converts an integer to a string.
 * @num: The integer to convert.
 *
 * Return: A pointer to the resulting string. NULL if memory allocation fails.
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
		n = -num;
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
