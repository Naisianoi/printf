#include "main.h"
#include <stdarg.h>
#include <stddef.h>

/**
 * _printf - produces output according to a format.
 * @format: list of arguments
 * Return: Printed thing
 */

int _printf(const char *format, ...)
{
	int printed_chars;

	convert_t f_list[BUFFSIZE] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_decimal},
		{"i", print_integer},
		{"x", _hex_l},
		{"X", _hex_u},
		{"p", _hex_l},
		{"S", print_string},
		{"r", print_r},
		{"R", rot_13},
		{"b", print_binary},
		{"u", print_unint},
		{"o", print_octal},
		{NULL, NULL},
	};
	va_list arg_list;

	if (format == NULL)
	
	{
		return (-1);
	}

	va_start(arg_list, format);
	/*fumc to be called*/
	printed_chars = parser(format, f_list, arg_list);

	va_end(arg_list);
	return (p_crs);
