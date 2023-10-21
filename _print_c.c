#include "main.h"

/**
 * print_c - prints a character.
 * @val: arguments.
 * Return: integer.
 */
int _print_c(va_list val)
{
	char s;

	s = va_arg(val, int);
	_putchar(s);
	return (1);
}
