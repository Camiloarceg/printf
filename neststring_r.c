#include "main.h"
#include <stdlib.h>
/**
 * neststring_r - allocate and nest the reverse string.
 * @buffer: nested string.
 * @i: funtion counter for printf.
 * @s: the string in the argument pointer.
 * @count: size of buffer.
 *
 * Return: the new buffer.
 */
char *neststring_r(char *buffer, char *s, int *count, int *i)
{
	unsigned int j = 1, len;

	if (s == NULL)
		s = "(null)";
	len = _strlen(s);
	while (j <= len)
	{
		buffer[*count] = s[len - j];
		*count += 1;
		j++;
	}
	*i += 1;
	return (buffer);
}
