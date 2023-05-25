#include "main.h"
/**
 * execute - executes the command
 * @cmd: Pointer to the command
 * @argv: Pointer to command's arguments
 * @av: Pointer to arguments
 * @envp: Pointer to env
 * Return: int
 */
int execute(const char *cmd, char **argv, char **av, char **envp)
{
pid_t pid;
int status;
char *full_path = NULL;

if (cmd[0] == '/')
{
if (access(cmd, X_OK) == 0)
{
full_path = strdup(cmd);
if (full_path == NULL) {
perror("Failed to allocate memory");
return (-1);
}
} else {
char error_message[100];
snprintf(error_message, sizeof(error_message), "%s: command not found\n", cmd);
write(STDERR_FILENO, error_message, strlen(error_message));
return COMMAND_NOT_FOUND;
}
} else {
if (!path(cmd, &full_path))
{
char error_message[100];
snprintf(error_message, sizeof(error_message), "%s: command not found\n", cmd);
write(STDERR_FILENO, error_message, strlen(error_message));
return COMMAND_NOT_FOUND;
}
}

pid = fork();
if (pid == -1)
{
perror(av[0]);
free(full_path);
return (-1);
} else if (pid == 0)
{
if (execve(full_path, argv, envp) == -1)
{
perror(av[0]);
_exit(EXIT_FAILURE);
}
} else {
if (wait(NULL) == -1)
{
perror(av[0]);
free(full_path);
return (-1);
}
}

free(full_path);

return (0);
}
