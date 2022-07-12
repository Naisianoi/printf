#include "main.h"

/**
 * get_op - select function for conversion char
 * @c: char to check
 *
 * Return: pointer
 */

int (*get_op(const char c))(va_list)
{
	int x = 0;

	flags_p fp[] = {
		{"c", print_char},
		{"s", print_str},
		{"i", print_nbr},
		{"d", print_nbr},
		{"b", print_binary},
		{"o", print_octal},
		{"x", print_hexa_lower},
		{"X", print_hexa_upper},
		{"u", print_unsigned},
		{"S", print_str_unprintable},
		{"r", print_str_reverse},
		{"p", print_ptr},
		{"R", print_rot13},
		{"%", print_percent}
	};
	while (x < 14)
	{
		if (c == fp[x].c[0])
		{
			return (fp[x].f);
		}
		++x;
	}
	return (NULL);
}

/*
 * _printf - prints anything
 * @format: the format string
 *
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int sum = 0, x = 0;
	int (*func)();

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(ap, format);

	while (format[x])
	{
		if (format[x] == '%')
		{
			if (format[x + 1] != '\0')
				func = get_op(format[x + 1]);
			if (func == NULL)
			{
				_putchar(format[x]);
				sum++;
				++x;
			}
			else
			{
				sum += func(ap);
				x += 2;
				continue;
			}
		}
		else
		{
			_putchar(format[x]);
			++sum;
			++x;
		}
	}
	va_end(ap);
	return (sum);
}
