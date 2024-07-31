#include "main.h"

/* 
 * Function to print integer (base 10) 
 * */
int print_d(va_list args) 
{
	int n = va_arg(args, int);
	return print_number(n);
}

