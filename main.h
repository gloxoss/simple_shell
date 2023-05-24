
#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>

#define MAX_COMMAND_LINE_LEN 1024
#define MAX_COMMAND_LINE_ARGS 128

int _putchar(char c);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
void prompt(void);
void exit_shell(void);
void execute(char *command, char **arguments);
char **parse(char *line);
void strip(char *str);
char *path(char *command);
char *_getenv(const char *name);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

#endif
