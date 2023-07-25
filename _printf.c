#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int char_count = 0;
	va_list args_list;

	va_start(args_list, format);
	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			char_count++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
				char_count++;
			}
			else if (*format == 'c')
			{
				char input = va_arg(args_list, int);

				write(1, &input, 1);
				char_count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args_list, char*);
				int len = strlen(str);

				write(1, str, len);
				char_count += len;
			}
		}
		format++;
	}
	va_end(args_list);
	return (char_count);
}
