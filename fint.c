#include "main.h"

/**
 * f_int - prints int
 * @valist: our valist
 * Return: the number of characters printed
 */
int f_int(va_list valist)
{
	int lenint = 0, i = va_arg(valist, int);
	unsigned int a, b, c = 1;

	if (i < 0)
	{
		a = -i;
		_putchar('-');
		lenint++;
	}
	else
		a = i;
	b = a;
	while (b > 9)
	{
		b /= 10;
		c *= 10;
	}
	while (c >= 1)
	{
		_putchar(((a / c) % 10) + '0');
		c /= 10;
		lenint++;
	}
	return (lenint);
}
