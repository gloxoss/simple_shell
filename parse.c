#include "main.h"
/**
 * parse -  parses the line into commands and arguments
 *@line : command line
 *Return :  value
 */
char **parse(char *line)
{
char **arguments = malloc(sizeof(char *) * (strlen(line) / 2 + 1));
if (arguments == NULL)
{
return (NULL);
}

int i = 0;
char *command = strtok(line, " ");
while (command != NULL)
{
arguments[i] = command;
command = strtok(NULL, " ");
i++;
}

return (arguments);
}
