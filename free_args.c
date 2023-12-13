#include "main.h"

void free_args(char **args, int count_args)
{
	int i;

	for (i = 0; i < count_args; i++)
	{
		free(args[i]);
	}
}
