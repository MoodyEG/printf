#include "main.h"

/**
 * f_string - print string
 * @valist: our valist
 * Return: the number of characters printed
 */
int f_string(va_list valist)
{
	char *a = va_arg(valist, char *);

	if (!a)
		a = "(null)";
	return (_puts(a));
}
