#include "main.h"
int main(void)
{
char *command;

while (1)
{

command = prompt();


if (!is_valid_command(command))
{
fprintf(stderr, "Error: Command must be a single word\n");
free(command);
continue;
}


if (access(command, X_OK) == -1)
{
fprintf(stderr, "Error: Command not found: %s\n", command);
free(command);
continue;
}


int status = system(command);
if (status == -1)
{
fprintf(stderr, "Error: Failed to execute command\n");
free(command);
continue;
}


free(command);
}

return 0;
}
