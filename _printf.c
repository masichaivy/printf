#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int char_count;

	char_count = 0;
	if (format == NULL)
		return (-1);

	va_list args_list;

	va_start(args_list, format);

	while(*format)
	{
		if(*format != '%')
		{
			write(1, format, 1);
			char_count++;
		}
		else {
			format++;
		}

		if (*format == 'c')
		{
			write(1, format, 1);
		}
	}
}
