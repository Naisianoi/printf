#include "main.h"

/**
 * _printf - produces output according to a format.
 * @format: list of arguments
 * Return: Printed thing
 */

int _printf(const char *format, ...)
{
	int crs;
	va_list list;

	va_start(list, format);
	if (format == NULL)
		return (-1);
	crs = charsFormats(format, list);

	va_end(list);
	return (crs);
}

/**
 * charsFormats - paremters printf
 * @format: list of arguments
 * @args: listing
 * Return: value of print
 */

int charsFormats(const char *format, va_list args)
{
	int x, y, crs, zxl;

	fmtsSpefier f_list[] = {{"c", _char}, {"s", _string},
		{"%", _percent}, {"d", _integer}, {"i", _integer}, {NULL, NULL}
	};
	crs = 0;
	for (x = 0; format[x] != '\0'; ++x)
	{
		if (format[x] == '%')
		{
			for (y = 0; f_list[y].sym != NULL; ++y)
			{
				if (format[x + 1] == f_list[y].sym[0])
				{
					zxl = f_list[y].f(args);
					if (zxl == -1)
						return (-1);
					crs += zxl;
					break;
				}
			}
			if (f_list[y].sym == NULL && format[x + 1] != ' ')
			{
				if (format[x + 1] != '\0')
				{
					_putchar(format[x]);
					_putchar(format[x + 1]);
					crs = crs + 2;
				}
				else
					return (-1);
			}
			x += 1:
		}
		else
		{
			_putchar(format[x]);
			crs++;
		}
	}
	return (crs);
}
