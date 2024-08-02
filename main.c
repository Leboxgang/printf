#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
        _printf("Hello, %s!\n", "World");
        _printf("Character: %c\n", 'A');
        _printf("Percentage: %%\n");
	_printf("%b\n", 98);

	return (0);
}
