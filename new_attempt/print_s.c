#include "main.h"

/**
 * print_s - Prints a string.
 * @val: Arguments.
 * 
 * Return: Number of characters printed.
 */
int print_s(va_list val)
{
    char *s;
    int i, len;

    s = va_arg(val, char *);
    if (s == NULL)
    {
        s = "(null)";
    }
    len = _strlen(s);
    for (i = 0; i < len; i++)
    {
        _putchar(s[i]);
    }
    return (len);
}
