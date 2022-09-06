
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


/**
 * multispawn - executes the command 'ls -l /tmp' in 5 different child processes
 * Each child should be created by the same process (the father). Wait for
 * the child to exit before creating a new child
 *
 * Return: always 0
 */

int main(void)
{
	pid_t childpid;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	int status, i;

	for (i = 0; i <= 4; i++)
	{
		/* 1. Create a new child process */
		childpid = fork();
		if (childpid == -1)
		{
			perror ("Error:");
			return (1);
		}
/*		printf("PID: %d\n", childpid);*/
		/* 2. Execute the command from the new child process */
		if (childpid == 0)
		{
			execve(argv[0], argv, NULL);
			sleep(.3);
		}
		else
		{
			wait(&status); /* 3. Wait for the child process to exit */
/*			puts("Child process has exited");*/
		}
	}
		/* 4. Repeat 5 times*/
	return (0);
}
