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
	char *p;
	unsigned int k = 0, j = 0, old_size = *count, len;

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
	while (k < old_size + len)
	{
		p[k] = s[j];
		k++;
		j++;
	}
	*i += 1;
	free(buffer);
	return (p);
}
