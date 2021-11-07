#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
/**
 * _printf - a function that produces output according to a format.
 * @format: format string.
 *
 * Return: count if chars printed.
 */
int _printf(const char *format, ...)
{
	int count, i = 0;
	char *buffer;
	va_list ap;

	va_start(ap, format);
	count = sizeof(char) * 1;
	buffer = (char *)malloc(count);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					buffer = nest(buffer, &count, &i, va_arg(ap, int));
					break;
				case 's':
					buffer = neststring(buffer, va_arg(ap, char *), &count, &i);
					break;
				case '%':
					buffer = nest(buffer, &count, &i, '%');
					break;
				case '\0':
					break;
				default:
					buffer = nest(buffer, &count, &i, '%');
					i--;
					buffer = nest(buffer, &count, &i, format[i]);
					break;
			}
			continue;
		}
		buffer = nest(buffer, &count, &i, format[i]);
	}
	write(1, buffer, count - 1);
	free(buffer);
	va_end(ap);
	return (count);
}
