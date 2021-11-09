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
	char *p;
	unsigned int k = 0, j = 0, old_size = *count, len;

	if (s == NULL)
		s = "(null)";
	len = _strlen(s);
	*count += len;

	p = (char *)malloc(*count);
	if (p == NULL)
	{
		free(p);
		return (NULL);
	}

	while (k < old_size)
	{
		p[k] = buffer[k];
		k++;
	}

	k = k - 1;
	len = len - 1;
	while (k < old_size + len)
	{
		p[k] = s[len - j];
		k++;
		j++;
	}
	*i += 1;
	free(buffer);
	return (p);
}
