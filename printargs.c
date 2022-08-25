#include <stdio.h>
#include <string.h>

/**
 * main - entry point
 * @ac: number of items in av
 * @av: a NULL terminated array of strings
 *
 * Return: 0 for successful operation
 */

int main(int ac, char **av)
{
	
	int i;

/*	av[ac] = NULL;*/
	i = 1;
	while (((av)[i]) != NULL)
		printf("%s\n", ((av)[i++]));
	return (0);
}
