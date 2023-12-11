#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_IN_SIZE 1024

void pass_betty(void);
void display_prompt(void);
char *read_input();
int sd_putchar(char c);
char *_strcpy(char *dest, char *src);
void execute_cmd(char *command);

#endif