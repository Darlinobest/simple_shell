#include "main.h"

/**
 * read_input - reads input of the user
 * Return: outputs whatever the user types
 */

char *read_input()
{
	char *input_to_prompt;
	size_t size_of_input_to_prompt;

	size_of_input_to_prompt = 0;
	input_to_prompt = NULL;
	display_prompt();

	getline(&input_to_prompt, &size_of_input_to_prompt, stdin);

	return (input_to_prompt);
}
