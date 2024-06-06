#ifndef ASHV2_H
#define ASHV2_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/stat.h>
#include <limits.h>

#define INPUT_SIZE 1024
#define TOKEN_DELIMITERS " \t\r\n\a"

extern char **environ;

void display_prompt(void);
char *read_input(void);
char **parse_input(char *input);
int execute_command(char **args);

int shell_cd(char **args);
int shell_exit(char **args);
int shell_env(char **args);

int _strcmp(const char *s1, const char *s2);
char *search_path(char *command);

#endif
