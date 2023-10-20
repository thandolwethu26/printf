#include "main.h"

int _printf(const char *format, ...)
{
    int printed_char = 0;

    va_list lists;
    va_start(lists, format);

    if (format == NULL)
    {
        return (-1);
    }

    while (*format)
    {
        if (*format != '%')
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
                char *hen = va_arg(lists, char *);
                int str_len = strlen(hen); // Use strlen to get the string length
                write(1, hen, str_len);
                printed_char += str_len;
            }
        }
        format++;
    }

    va_end(lists);
    return (printed_char);
}
