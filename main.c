#include "main.h"

/**
 * main - perfoms the logic for running shell
 * Return: 0 upon success, or exit/disconnected when crtl D
 * is encounted
 */
int main(void)
{
	pid_t pid;


	pass_betty();
	while (1)
	{
		char *command;
		char exit_message[25] = "\nExit\n\nDisconnected...\n";

		command = read_input();
		if (feof(stdin) || !_strcmp(command, "exit\n"))
		{
			free(command);
			write(STDOUT_FILENO, exit_message, sizeof(exit_message) - 1);
			exit(EXIT_SUCCESS);
		}
		if (strlen(command) > 1)
		{
			pid = fork();

			if (pid == -1)
				perror("Bash");
			else if (pid == 0)
			{
				execute_cmd(command);
				_exit(EXIT_SUCCESS);
			}
			else
				waitpid(pid, NULL, 0);
		}
		free(command);
	}
	return (0);
}
