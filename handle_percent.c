#include <unistd.h>

/**
 * handle_percent - Handles the '%' conversion specifier.
 *
 * Return: The number of characters printed.
 */
int handle_percent(void)
{
	write(1, "%", 1);
	return (1);
}
