#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
/**
 * switch_case_adv - switch case for advance functions.
 * @buffer: pointer to buffer.
 * @format: pointer to format.
 * @count: pointer to count.
 * @ap: argument pointer
 * @i: index for format.
 *
 * Return: new buffer.
 */
char *switch_case_adv(char *buffer, const char *format, int *count,
		va_list ap, int *i)
{
	switch (format[*i])
	{
		case 'r':
			buffer = neststring_r(buffer, va_arg(ap, char *), count, i);
			break;
		case 'b':
			buffer = nest_bin(buffer, count, i, va_arg(ap, int));
			break;
		default:
			break;
	}
return (buffer);
}

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
			if (format[i] == 'r' || format[i] == 'b')
			{
				buffer = switch_case_adv(buffer, format, count, ap, &i);
				continue;
			}
			switch (format[i])
			{	case 'c':
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
					return (NULL);
				default:
					buffer = nest(buffer, count, &i, '%');
					i--;
					buffer = nest(buffer, count, &i, format[i]);
					break;
			} continue;
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
	if (!format || !buffer || (*format == '%' && *(format + 1) == '\0'))
	{
		va_end(ap);
		free(buffer);
		return (-1);
	}

	buffer = switch_case(buffer, format, &count, ap);
	if (!buffer)
	{
		va_end(ap);
		return (-1);
	}
	count -= 1;
	write(1, buffer, count);
	free(buffer);
	va_end(ap);
	return (count);
}
