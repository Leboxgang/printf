#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

int _printf(const char *format, ...);
int print_char(char c);
int print_string(char *str);

/*helper functions*/
char *uint_to_binary(unsigned int num);
char *custom_strdup(const char *str);

#endif
