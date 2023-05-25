#include "main.c"

/**
 * print_environment - prints the environment
 * @envp: Pointer to the environment variables
 */
void print_environment(char **env)
{
if (env == NULL)
{
write(STDERR_FILENO, "env is NULL\n", 12);
return;
}

for (int i = 0; env[i] != NULL; i++)
{
write(STDOUT_FILENO, env[i], strlen(env[i]));
write(STDOUT_FILENO, "\n", 1);
}
}
