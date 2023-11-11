#include "main.h"

/**
 * _puts - a function that prints a string, followed by a new line, to stdout
 * @str: pointer to our char
 * Return: how many printed
 */
int _puts(char *str)
{
	int a = 0;

	while (str[a])
	{
		_putchar(str[a]);
		a++;
	}

	return (a);
}
