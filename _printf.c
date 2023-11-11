#include "main.h"

/**
 * f_char - prints char
 * @valist: our valist
 * Return: the number of characters printed
 */
int f_char(va_list valist)
{
	char a = va_arg(valist, int);

	return (_putchar(a));
}
/**
 * f_string - print string
 * @valist: our valist
 * Return: the number of characters printed
 */
int f_string(va_list valist)
{
	return (_puts(va_arg(valist, char *)));
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
