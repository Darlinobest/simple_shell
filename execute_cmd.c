#include "main.h"

/**
 * execute_cmd - execute the various command
 * @command: command given by the user
 */
void execute_cmd(char *command)
{
	int i, count_args;
	char *args[100];
	char *exec_path, *err_mess, *err_message;

	err_message = "Command not found\n";
	err_mess = "Error running command\n";
	command[strcspn(command, "\n")] = '\0';

	if (_strcmp(command, "env") == 0)
	{
		execute_env();
		return;
	}
	if (_strcmp(command, "exit") == 0)
	{
		write(STDOUT_FILENO, "\nDisconnected\n", sizeof("\nDisconnected\n") - 1);
		exit(EXIT_SUCCESS);
	} exec_path = check_cmd(command);
	if (exec_path == NULL)
	{
		write(STDOUT_FILENO, err_message, strlen(err_message));
		return;
	}
	tokenize_cmd(command, args, &count_args);
	for (i = 0; i < count_args; i++)
	{
		printf("args[%d]: %s\n", i, args[i]);
	}
	if (execve(exec_path, args, NULL) == -1)
	{
		write(STDERR_FILENO, err_mess, strlen(err_mess));
		sd_putchar('\n');
		exit(EXIT_FAILURE);
	}
	free_args(args, count_args);
}
