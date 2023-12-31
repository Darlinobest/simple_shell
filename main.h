#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_INPUT_SIZE 1024

extern char **environ;

void pass_betty(void);
void display_prompt(void);
char *read_input();
int sd_putchar(char c);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *check_cmd(char *command);
void tokenize_cmd(char *cmd, char ***args, int *num_token);
void execute_cmd(char *command);
void free_args(char **args, int count_args);
void execute_env(void);

#endif
