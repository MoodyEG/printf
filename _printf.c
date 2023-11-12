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
/**
 * f_percent - prints percent
 * @valist: our valist
 * Return: the number of characters printed
 */
int f_percent(va_list valist)
{
	(void)valist;
	return (_putchar('%'));
}
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
		c /= c;
		lenint++;
	}
	return (lenint);
}
/**
 * _printf - prints what you want, followed by a new line.
 * @format: types of arguments passed to the function
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, j, len = 0;
	char *percent = "%";
	va_list valist;
	iden_t iden[] = {
		{"c", f_char},
		{"s", f_string},
		{"%", f_percent},
		{"d", f_int},
		{"i", f_int},
		{NULL, NULL},
	};

	va_start(valist, format);
	while (format && format[i])
	{
		if (format[i] && format[i] != percent[0])
		{
			len += _putchar(format[i]);
			i++;
			continue;
		}
		else if (format[i] == '%' && format[i + 1])
		{
			i++;
			j = 0;
			while (iden[j].iden)
			{
				if (format[i] == iden[j].iden[0])
				{
					len += iden[j].f(valist);
					break;
				}
				j++;
			}
		}
		i++;
	}
	va_end(valist);
	_putchar('\n');
	return (len);
}
