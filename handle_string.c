#include <unistd.h>
#include <stdarg.h>

/**
 * handle_string - Handles the 's' conversion specifier.
 * @args: The argument list.
 *
 * Return: The number of characters printed.
 */
int handle_string(va_list args)
{
	char *s = va_arg(args, char *);
	int count = 0;

	if (s)
	{
		while (*s)
		{
			write(1, s++, 1);
			count++;
		}
	}
	else
	{
		write(1, "(null)", 6);
		count += 6;
	}
	return (count);
}
