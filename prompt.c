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
	size_t *restrict n;
	char **restrict buf;
	FILE *restrict stream;

	stream = STDIN_FILENO;
	printf("Stream assigned\n");
	*n = MAXCHARS;
	printf("n assigned\n");
	buf = malloc(*n * sizeof(buf));
	printf("Space for buffer allocated");
	printf("$ ");
	gd = getline(buf, n, stream);
	if (gd < 0)
		exit(-1);
	printf("%s\n", *buf);
	free(buf);
	return (0);
}
