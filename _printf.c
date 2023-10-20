#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int printed_char = 0;

	va_list lists;

	if (*format == NULL)
	{
		return (-1);
	}

	va_start(lists, format);
	while (*format)
	{
		if (format != '%')
		{
			write(1, format, 1);
			printed_char++;
		}
		else
		{
			format++;
			if (*format == '\0')
			break;
			if (*format == '%')
			{
				write(1, format, 1);
				printed_char++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(lists, int);

				write(1, &c, 1);
				printed_char++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(lists, char*);
				int str_len = 0;

				while (str(str_len) != '\0')
				{
					str_len++;
				}
				write(1, str, str_len);
				printed_char += str_len;
			}
		}
		format++;
	}

	va_end(lists);

	return (printed_char);
}
