#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * strsplit - splits a string a returns an array of each word of the string
 *
 * Return: 0 for successful execution
 */

int main(void)
{
	ssize_t gd;
	/*FILE *stream;*/
	size_t *n, m;/*, j;*/
	char **lineptr, *str, *token;

	m = 20;
	n = &m;
	lineptr = malloc(*n);
	printf("$:");
	gd = getline(lineptr, n, stdin);
/*	printf("gd: %ld\n", gd);*/
	if (gd < 0)
	{
		free(lineptr);
		puts("Error reading from stdin");
		exit(EXIT_FAILURE);
	}
	/* ssize_t getline(char **restrict lineptr, size_t *restrict n, FILE *restrict stream)*/
	/* char *strtok(char *restrict str, const char *restrict delim)*/
	str = *lineptr;
	token = strtok(str, " ");
	printf("%s\n", token);
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}
	free(lineptr);
	return (0);
}

/** TO DO: Write my own version of strtok
 */
