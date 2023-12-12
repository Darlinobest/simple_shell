#include "main.h"

/**
 * execute_env - prints current environment
 */

void execute_env(void)
{
	char **env;

	env = environ;
	while (*env != NULL)
	{
		write(STDOUT_FILENO, *env, strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}
