#include "main.h"

/**
 * execute_cmd - execute the various command
 * @command: command given by the user
 */
void execute_cmd(char *command)
{
	int count_args;
	char *token, *err_message;
	char *args[100];
	char *exec_path, *err_mess;

	err_message = "Command not found\n";
	err_mess = "Error running command\n";
	command[strcspn(command, "\n")] = '\0';
	exec_path = check_cmd(command);

	if (exec_path == NULL)
	{
		write(STDOUT_FILENO, err_message, strlen(err_message));
		return;
	}
	token = strtok(command, " ");
	count_args = 0;
	while (token != NULL)
	{
		args[count_args++] = token;
		token =  strtok(NULL, " ");
	}
	args[count_args] = NULL;

	if (execve(exec_path, args, environ) == -1)
	{
		write(STDERR_FILENO, err_mess, strlen(err_mess));
		sd_putchar('\n');
		exit(EXIT_FAILURE);
	}
}
