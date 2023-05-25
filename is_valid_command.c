#include "main.h"
/**
 * exit -  exits the shell
 * Return: Void
 */
int is_valid_command(char *command)
{
/* Check if the command contains any spaces*/
int length = strlen(command);
for (int i = 0; i < length; i++)
{
if (command[i] == ' ')
{
return 0;
}
}
return 1;
}
