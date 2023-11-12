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
int _puts(char *str);
int f_char(va_list valist);
int f_string(va_list valist);
int f_percent(va_list valist);
int f_anyway(char str);
int f_int(va_list valist);
int f_binary(va_list valist);
int get_f(char fword, va_list valist);
int _printf(const char *format, ...);

#endif /* MAIN_H */
