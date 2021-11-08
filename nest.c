#include "main.h"
#include <stdlib.h>
/**
 * nest - nest a string.
 * @buffer: the buffer to print.
 * @count: pointer to the char count of the buffer.
 * @i: index of format.
 * @c: char to nest.
 *
 * Return: pointer to the new buffer.
 */
char *nest(char *buffer, int *count, int *i, char c)
{
	char *p;
	int j = 0;

	p = (char *)malloc(*count + 1);
	if (p == NULL)
		return (NULL);
	while (j < *count)
	{
		p[j] = buffer[j];
		j++;
	}
	p[j - 1] = c;
	p[j] = '\0';
	free(buffer);
	*i += 1;
	*count += 1;
	return (p);
}
