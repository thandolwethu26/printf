#include "main.h"
/**
 * _printf - is a function that selects the correct function to print.
 * @format: identifier to look for.
 * Return: the length of the string.
 */
int _printf(const char * const format, ...)
{
	work p[] = {
		{"%s", _print_s}, {"%c", _print_c},
		{"%%", _print_37},
		{"%i", _print_i}, {"%d", _print_d}
	};

	va_list args;
	int i = 0, k, length = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Here:
	while (format[i] != '\0')
	{
		k = 4;
		while (k >= 0)
		{
			if (p[k].q[0] == format[i] && p[k].q[1] == format[i + 1])
			{
				length += p[k].funct(args);
				i = i + 2;
				goto Here;
			}
			k--;
		}
		_putchar(format[i]);
		length++;
		i++;
	}
	va_end(args);
	return (length);
}
