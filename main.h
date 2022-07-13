#ifndef HEADER_FILE
#define HEADER_FILE

/* import some libraries */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

typedef struct formats
{
	char *sym;
	int (*f)(va_list);
} fmtsSpefier;

int _putchar(char c);
int _printf(const char *format, ...);
int charsFormats(const char *format, va_list args);
int _percent(va_list list);
int _char(va_list list);
int _string(va_list list);
int _integer(va_list list);
int b_print(va_list args);
int c_print(va_list args);
int print_char(va_list list);
int print_string(va_list list);
int print_percent(__attribute__((unused))va_list list;
int print_integer(va_list list);
int print_decimal(va_list list);

#endif
