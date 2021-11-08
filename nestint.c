#include "main.h"
#include <stdlib.h>
/**
 * nest_int - nest a string.
 * @buffer: the buffer to print.
 * @count: pointer to the char count of the buffer.
 * @i: index of format.
 * @n: number to nest.
 *
 * Return: pointer to the new buffer.
 */
char *nest_int(char *buffer, int *count, int *i, int n)
{
	unsigned int x;
	int j = 1;

	if (n < 0)
	{
		buffer = nest(buffer, count, i, '-');
		x = -n;
	}

	else
		x = n;

	if (x / 10)
		buffer = nest_int(buffer, count, &j, x / 10);

	buffer = nest(buffer, count, i, x % 10 + '0');

	return (buffer);
}
