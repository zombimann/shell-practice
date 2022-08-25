#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#ifndef MAX_CHARS
#define MAX_CHARS 20
#endif

/**
 * nain - pid_max
 *
 * Return: zero for successful execution
 */

int main(void)
{
	int fd, count, cd;
	ssize_t rd;
	char *buf;

	count = MAX_CHARS;
	fd = open("/proc/sys/kernel/pid_max", O_RDONLY);
	if (fd < 0)
		exit(-1);
	buf = malloc(count * sizeof(buf));
	rd = read(fd, buf, count);
	if (rd < 0)
		exit(-1);

	printf("%s\n", buf);
	cd = close(fd);
	if (cd < 0)
		exit(-1);
	return (0);
}
