#include "main.h"
#include <stdlib.h>
/**
 * nest_bin - nest an binary.
 * @buffer: the buffer to print.
 * @count: pointer to the char count of the buffer.
 * @i: index of format.
 * @n: number to nest.
 *
 * Return: pointer to the new buffer.
 */
char *nest_bin(char *buffer, int *count, int *i, int n)
{
	unsigned int x;
	int b, j;

	if (n == 0)
	{
		buffer = nest(buffer, count, i, '0');
		return (buffer);
	}

	if (n < 0)
	{
		free(buffer);
		return (NULL);
	}

	x = n;
	b = x % 2;
	x = x / 2;

	if (x >= 2)
	{
		buffer = nest_bin(buffer, count, &j, x);
	}
	else
		buffer = nest(buffer, count, &j, x + '0');

	buffer = nest(buffer, count, i, b + '0');

	return (buffer);
}
