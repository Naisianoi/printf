#include "main.h"

/**
 * _printf - receive the main string and all arguments
 * to print a formated string
 * @format: string containing all the desired characters
 * Return: the number of characters printed (without the null byte)
 */

int _printf(const char *format, ...)
{
	int chars;
	va_list list;

	va_start(list, format);
	if (format == NULL)
		return (-1);

	chars = charsFormats(format, list);

	va_end(list);
	return (chars);
}
