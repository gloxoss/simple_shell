#include "shell.h"
/**
 * prompt - prompts the user for input
 * @argv: Pointer to array of arguments
 * @envp: Pointer to the environment
 * Return: int
 */

int prompt(char **argv, char **env)
{
char *line = NULL;
size_t len = 0;
ssize_t read;
char *token;
int status = 1;
int execute_status = 0;

while (status)
{
line = NULL;
if (isatty(STDIN_FILENO))
{
write(STDOUT_FILENO, "$ ", 2);
}
read = getline(&line, &len, stdin);
if (read == -1)
{
if (line != NULL)
{
free(line);
}
break;
}
if (line[0] == '\n')
{
free(line);
continue;
}

token = strtok(line, " \t\n");
if (token == NULL) {
free(line);
continue;
}
if (strcmp(token, "exit") == 0)
{
status = 0;
free(line);
break;
}

execute_status = execute(token, argv, env);
free(line);

if (execute_status == -1)
{
break;
}
}

    return execute_status;
}
