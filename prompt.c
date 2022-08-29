#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

#ifndef MAXCHARS
#define MAXCHARS 100
#endif

/**
 * main - requests for user input
 *
 * Return: 0 for successful operation
 */

int main(void)
{
	ssize_t gd;
	size_t *restrict n, m;
	char **restrict buf;
	int *restrict stream, filedes;

	stream = &filedes;
	*stream = STDIN_FILENO;
/*	printf("Stream assigned\n");*/
	m = MAXCHARS;
	n = &m;
/*	printf("n assigned\n");*/
	buf = malloc(*n);
	if (buf == NULL)
		puts("Buffer space not allocated");
/*	printf("Space for buffer allocated\n");*/
	gd = 0;
	while (gd > -1)
	{
		printf("$ ");
		gd = mygetline(buf, n, stream);
		*buf[*n] = EOF; 
		puts("gets here");
		printf("%s\n", *buf);
	}
	free(buf);
	return (0);
}


/**
 * mygetline - Reads a a string from stdin until it finds a '\n or EOF
 * @bug: a pointer to an array on which to store the string
 * @n: size of the buffer
 * @stream: the file descriptor. In this case, we'll use stdin
 *
 * Return: The number of of characters atually written or -1 on failure
 */

ssize_t mygetline(char **restrict buf, size_t *restrict n, int *restrict stream)
{
	ssize_t rd;
/*	char ch;*/
	buf = malloc(*n);

	rd = read(*stream, buf, *n);
/*	puts("reaches here");*/

	printf ("rd : %ld\n", rd);
/*	puts("Successfully accessed the function");*/

	return (rd);
}
