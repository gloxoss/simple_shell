#include "main.h"
/**
 * exit -  exits the shell
 * Return: Void
 */
int is_valid_command(const char *command)
{
    
int length = strlen(command);
int i;
for (i = 0; i < length; i++)
{
if (command[i] == ' ')
{
return 0;
}
}
return 1;
}
