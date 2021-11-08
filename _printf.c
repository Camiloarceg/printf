#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
/**
 * switch_case - switch case functions.
 * @buffer: pointer to buffer.
 * @format: pointer to format.
 * @count: pointer to count.
 * @ap: argument pointer
 *
 * Return: new buffer.
 */
char *switch_case(char *buffer, const char *format, int *count, va_list ap)
{
	int i = 0;

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					buffer = nest(buffer, count, &i, va_arg(ap, int));
					break;
				case 's':
					buffer = neststring(buffer, va_arg(ap, char *), count, &i);
					break;
				case '%':
					buffer = nest(buffer, count, &i, '%');
					break;
				case 'i':
					buffer = nest_int(buffer, count, &i, va_arg(ap, int));
					break;
				case 'd':
					buffer = nest_int(buffer, count, &i, va_arg(ap, int));
					break;
				case '\0':
					break;
				default:
					buffer = nest(buffer, count, &i, '%');
					i--;
					buffer = nest(buffer, count, &i, format[i]);
					break;
			}
			continue;
		}
		buffer = nest(buffer, count, &i, format[i]);
	}
	return (buffer);
}

/**
 * _printf - a function that produces output according to a format.
 * @format: format string.
 *
 * Return: count if chars printed.
 */
int _printf(const char *format, ...)
{
	char *buffer;
	int count;
	va_list ap;

	va_start(ap, format);
	count = sizeof(char) * 1;
	buffer = (char *)malloc(count);
	if (buffer == NULL)
		return(NULL);
	buffer = switch_case(buffer, format, &count, ap);
	write(1, buffer, count);
	free(buffer);
	va_end(ap);
	return (count);
}
