#include "main.h"
/**
 * _getenv - get env
 * @name: Name of the environment variable to retrieve
 * Return: Pointer to the value of the env,or NULL 
 */
char *_getenv(const char *name)
{
char **env = environ;
while (*env != NULL)
{
if (strcmp(*env, name) == 0)
{
return (*env);
}
env++;
}

return (NULL);
}
