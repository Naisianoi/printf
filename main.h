#ifndef PRINTF
#define PRINTF

/* import some libraries */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#define BUFFSIZE 1024

/**
 * struct convert - defines a struct for sumbols and functions
 * @sym: The operator
 * @f: the function associated to symbol
 */

typedef struct convert

{
	char *sym;
	int (*f)(va_list);
} convert_t;

/**
 * struct modifier - mofifier fields collection
 * @flags: flags field composed of ['0', ' ', '#', '+', '-']
 * @width: width field, positive number
 * @precision: precision field positive number not including '.'
 * or -1 for '*'
 * @length: length field string composed of ['h', 'l']
 * @specifier: specifier character can one of
 * ['c', 's', '%', 'd', 'i', 'b', 'u', 'o', 'x', 'X', 'S', 'p', 'r', 'R']
 */

typedef struct modifier

{
	char *flags;
	int width;
	int precision;
	char *length;
	char specifier;
} modifier_t;

/*Main functions*/

int parser(const char *format, convert_t f_list[], va_list arg_list);
int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list);
int print_string(va_list);
int print_percent(__attribute__((unused))va_list);
int print_integer(va_list list);
int print_decimal(va_list list);
int rot_13(va_list list);
int print_octal(va_list list);
int print_unint(va_list list);
int print_binary(va_list list);
int binary_recursive(unsigned int num, int len);
int _hex_str(unsigned int n, unsigned int hex, char alpha);
int _hex_l(va_list list);
int _hex_u(va_list list);
int str(va_list list);
int rev_string(__attribute__((unused))va_list list, char *s, ...);
int print_r(va_list list);

#endif
