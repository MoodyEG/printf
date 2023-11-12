#include "main.h"

/**
 * f_char - prints char
 * @valist: our valist
 * Return: the number of characters printed
 */
int f_char(va_list valist)
{
	char a = (char) va_arg(valist, int);

	return (_putchar(a));
}
