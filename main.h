#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>






typedef struct format
{
	char *q;
	int (*funct)();
} work;

int _printf(const char *format, ...);
int _print_i(va_list args);
int _print_d(va_list args);
int _print_c(va_list val);
int _print_s(va_list val);
int _print_37(void);


#endif
