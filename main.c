#include "main.h"

/**
 *
 */
int main(int argc, char *argv[])
{
	char *prompt,  *lineptr = NULL, *token, *lineptr_copy = NULL;
	size_t prompt_length, n = 0;
	ssize_t read_char;
	const char *delimiter = " \n";
	int i, n_token = 0;
	(void)argc;

	pass_betty();
	prompt = "sam_Darl:/$ ";
	prompt_length = strlen(prompt);
	while (1)
	{
		write(STDOUT_FILENO, prompt, prompt_length);
		lineptr = NULL;
		read_char = getline(&lineptr, &n, stdin);
		if (read_char == -1)
		{
			write(STDOUT_FILENO, "Exit\n\nDisconnected\n", 25);
			free(lineptr);
			return (-1);
		}
		lineptr_copy = malloc(sizeof(char) * read_char);
		if (lineptr_copy == NULL)
		{
			perror("Memory allocation failed");
			return (-1);
		}
		_strcpy(lineptr_copy, lineptr);
		token = strtok(lineptr, delimiter);
		while (token != NULL)
		{
			n_token++;
			token = strtok(NULL, delimiter);
		}
		n_token++;
		argv = malloc(sizeof(char *) * n_token);
		token = strtok(lineptr, delimiter);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			_strcpy(argv[i], token);
			token = strtok(NULL, delimiter);
		}
		argv[i] = NULL;
		execmd(argv);
		/*write(STDOUT_FILENO, lineptr, read_char);*/
		/*free(lineptr);*/
	}
	free(lineptr);
	sd_putchar('\n');
	return (0);
}
