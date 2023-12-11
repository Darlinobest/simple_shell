#include "main.h"

/**
 * display_prompt - displays prompt for the user
 * Return: whatever the user types
 */

void display_prompt(void)
{
	char prompt[13] = "sam_Darl:/$ ";

	write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
}
