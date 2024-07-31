#include <unistd.h>
#include <stdarg.h>

/**
 * handle_char - Handles the 'c' conversion specifier.
 * @args: The argument list.
 *
 * Return: The number of characters printed.
 */
int handle_char(va_list args)
{
	char c = (char) va_arg(args, int);

	write(1, &c, 1);
	return (1);
}
