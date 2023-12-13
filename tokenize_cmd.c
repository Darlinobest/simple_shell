#include "main.h"

/**
 * tokenize_cmd - breakdown cmd into bits
 * @cmd: command to be handled
 * @args: arg to command
 * @num_token: token count
 */

void tokenize_cmd(char *cmd, char ***args, int *num_token)
{
	char *token;
	const char *delim;
	int i;

	delim = " ";
	token = strtok(cmd, delim);
	
	while (token != NULL)
	{
		(*num_token)++;
		token = strtok(NULL, delim);
	}
	(*num_token)++;
	*args = (char **)malloc(sizeof(char *) * (*num_token + 1));
	token = strtok(cmd, delim);

	for (i = 0; token != NULL; i++)
	{
		(*args)[i] = (char *)malloc(sizeof(char) * (strlen(token) + 1));
		_strcpy((*args)[i], token);
		token = strtok(NULL, delim);
	}
	(*args)[i] = NULL;
}
