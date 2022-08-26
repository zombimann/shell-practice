#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
	FILE *restrict stream;

	stream = stdin;
/*	printf("Stream assigned\n");*/
	m = MAXCHARS;
	n = &m;
/*	printf("n assigned\n");*/
	buf = malloc(*n);
/*	printf("Space for buffer allocated\n");*/
	gd = 0;
	while (gd != -1)
	{
		printf("$ ");
		gd = getline(buf, n, stream);
		printf("%s\n", *buf);
	}
	free(buf);
	return (0);
}
