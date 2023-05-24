#include "main.h"
/**
 * path - finds the  path of a command
 * @command: Pointer to the command
 * Return: path
 */
char *path(char *command)
{
char *path_env = _getenv("PATH");
if (path_env == NULL)
{
return (NULL);
}

char *full_path = malloc(_strlen(path_env) + _strlen(command) + 2);
if (full_path == NULL) {
return (NULL);
}

_strcpy(full_path, path_env);
_strcat(full_path, "/");
_strcat(full_path, command);

if (access(full_path, F_OK) == 0)
{
return full_path;
}
else
{
return (NULL);
}
}

