#include "main.h"

/**
 * sd_putchar - prints a char
 * @c: the char to be printed
 * Return: size of bytes
 */

int sd_putchar(char c)
{
	return (write(1, &c, 1));
}
