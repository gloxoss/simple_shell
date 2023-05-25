#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stddef.h>
#include <signal.h>
#include <stdarg.h>
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>

#define MAX_INPUT_SIZE 1024
#define COMMAND_NOT_FOUND 127
#define static

extern char **environ;


int execute(char *cmd, char **argv, char **av, char **envp);
int prompt(char **argv, char **env);
char** split_string(const char* line);
int path(char *cmd, char **full_path) ;
char *_getenv(const char *name);
void hundle_ctrl(int signal);
void handle_sigint(int signum);
void setup_signal_handler();
int path(char *cmd, char **full_path);
void print_environment(char **env);


/*String's Functions*/

int _atoi(char *s);
bool is_num(const char *str);
int _strncmp(const char *s1, const char *s2, size_t n);
int _strcmp(char *s1, char *s2);
int _putchar(char c);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);


#endif
