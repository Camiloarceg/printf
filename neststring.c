#include "main.h"
#include <stdlib.h>
/**
 * neststring - allocate and nest the string.
 * @buffer: nested string.
 * @i: funtion counter for printf.
 * @s: the string in the argument pointer.
 * @count: size of buffer.
 *
 * Return: the new buffer.
 */
char *neststring(char *buffer, char *s, int *count, int *i)
{
	unsigned int j = 0, len;

	if (s == NULL)
		s = "(null)";
	len = _strlen(s);
	while (j < len)
	{
		buffer[*count] = s[j];
		*count += 1;
		j++;
	}
	*i += 1;
	return (buffer);
}
