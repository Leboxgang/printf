#include "main.h"

/* 
 * Function to print integer (base 10) 
 */
int print_i(va_list args)
{
	int n = va_arg(args, int);
	return print_number(n);
}
