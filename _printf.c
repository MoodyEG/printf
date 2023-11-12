#include "main.h"

/**
 * _printf - prints what you want, followed by a new line.
 * @format: types of arguments passed to the function
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, len = 0;
	char *percent = "%";
	va_list valist;

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
			len += get_f(format[i], valist);
		}
		i++;
	}
	va_end(valist);
	return (len);
}
