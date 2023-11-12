#include "main.h"

/**
 * f_binary - prints binary
 * @valist: our valist
 * Return: the number of characters printed
 */
int f_binary(va_list valist)
{
	int lenint = 0, i = va_arg(valist, int);
	unsigned int a, b, c = 1;

	if (i == 0)
	{
		_putchar('0');
		lenint++;
	}
	else if (i < 0)
	{
		a = -i;
		_putchar('-');
		lenint++;
	}
	else
		a = i;
	b = a;
	while (b > 1)
	{
		b /= 2;
		c *= 2;
	}
	while (c >= 1)
	{
		_putchar(((a / c) % 2) + '0');
		c /= 2;
		lenint++;
	}
	return (lenint);
}
