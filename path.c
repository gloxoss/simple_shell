#include "main.h"

/**
 * path -  finds the path of a command
 * @cmd: Pointer to the command
 * @full_path: Pointer to store the path of the command
 * Return: 1 on success, 0 if command not found
 */
int path(const char *cmd, char **full_path)
{
char *path_env = getenv("PATH");
char *path_token, *path_dup;
char *temp_path;
int found = 0;

if (path_env == NULL)
{
printf("PATH environment variable not found\n");
return (0);
}

path_dup = strdup(path_env);
if (path_dup == NULL)
{
perror("Failed to duplicate PATH environment variable");
return (0);
}

path_token = strtok(path_dup, ":");
while (path_token != NULL)
{
temp_path = malloc(strlen(path_token) + strlen(cmd) + 2);
if (temp_path == NULL)
{
perror("Failed to allocate memory");
free(path_dup);
return (0);
}
sprintf(temp_path, "%s/%s", path_token, cmd);
if (access(temp_path, X_OK) == 0)
{
*full_path = temp_path;
found = 1;
break;
}
free(temp_path);
path_token = strtok(NULL, ":");
}

free(path_dup);

return (found);
}
