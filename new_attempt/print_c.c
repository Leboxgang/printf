#include "main.h"

/**
 * print_c - Prints a character.
 * @val: Arguments.
 * 
 * Return: Number of characters printed.
 */
int print_c(va_list val)
{
    char s;

    s = va_arg(val, int);
    _putchar(s);
    return (1);
}
