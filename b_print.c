#include "main.h"

/**
 * b_print - prints unsigned ints as binary code
 * @args: variable argument coming from _printf
 * Return: output length in bytes/chars
 */

int b_print(va_list args)
{
	unsigned int dec = va_arg(args, unsigned int);
	char *bin;
	unsigned int pow_2 = 1;
	int count = 1;
	int i;

	while (pow_2 <= (dec / 2))
	{
		pow_2 *= 2;
		count++;
	}

	bin = malloc(sizeof(char) * (count + 1));
	if (!bin)
	{
		free(bin);
		return (-1);
	}
	for (i = 0; i < count; i++)
	{
		bin[i] = ((dec / pow_2) + '0');
		dec %= pow_2;
		pow_2 /= 2;
	}
	bin[i] = '\0';
	for (i = 0; bin[i]; i++)
		putchar(bin[i]);
	putchar('\n');
	free(bin);
	return (count);
}
