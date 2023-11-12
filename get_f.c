#include "main.h"

/**
 * get_f - choose the fundction
 * @fword: what type of fundction
 * @valist: our valist
 * Return: the number of characters printed
 */
int get_f(char fword, va_list valist)
{
	int  j = 0, len2 = 0;
	iden_t iden[] = {
		{"c", f_char}, {"s", f_string},
		{"%", f_percent}, {"d", f_int},
		{"i", f_int}, {"b", f_binary},
		{NULL, NULL},
	};

	while (iden[j].iden)
	{
		if (fword == iden[j].iden[0])
		{
			len2 += iden[j].f(valist);
			break;
		}
		j++;
	}
	if (!iden[j].iden)
	{
		len2 += f_anyway(fword);
	}
	return (len2);
}
