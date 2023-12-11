#include "main.h"

/**
 * execute_cmd - execute the various command
 * @command: command given by the user
 */
void execute_cmd(char *command)
{
	pid_t pid;

	command[strcspn(command, "\n")] = '\0';

	pid = fork();
	if (pid == -1)
		perror("fork");
	else if (pid == 0)
	{
		if (execlp(command, command, NULL) == -1)
		{
			perror("Bash");
			_exit(EXIT_FAILURE);
		}
	} else
	{
		waitpid(pid, NULL, 0);
	}
}
