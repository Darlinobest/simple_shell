#include "main.h"

/**
 * check_cmd - finds executable cmd
 * @command: executable command to be checked
 * Return: Expansion of command
 */

char *check_cmd(char *command)
{
	char *path, *path_copy, *dir;

	path = getenv("PATH");
	path_copy = strdup(path);
	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		char cmd_path[MAX_INPUT_SIZE];

		snprintf(cmd_path, sizeof(cmd_path), "%s/%s", dir, command);
		if (access(cmd_path, X_OK) == 0)
		{
			free(path_copy);
			return (strdup(cmd_path));
		}
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
