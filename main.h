#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

typedef struct iden iden_t;

/**
 * struct iden - identify the format
 * @iden: the formatting letter
 * @f: the function called
 */
struct iden
{
	char *iden;
	int (*f)(va_list);
};

int _putchar(char c);
int _printf(const char *format, ...);
int _puts(char *str);
int f_percent();

#endif /* MAIN_H */
