#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int handle_char(va_list args);
int handle_string(va_list args);
int print_number(int num);
int handle_percent(void);

#endif
