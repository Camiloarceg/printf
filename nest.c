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

	buffer[*count] = c;
	*i += 1;
	*count += 1;
	return (buffer);
}
