#include "main.h"

/**
 * _strcmp - function that compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 if they are equal, less than 0 if s1 < s2,
 * greater than 0 if s1 > s2
 */

int _strcmp(char *s1, char *s2)
{
	for (; *s1 == *s2; s1++, s2++)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
	}
	return (*s1 - *s2);
}
