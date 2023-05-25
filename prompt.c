#include "main.h"
/**
 * prompt -  start prompt
 * Return: void
 */
char *prompt()
{
char *command = malloc(MAX_COMMAND_LENGTH * sizeof(char));

/* Display the prompt*/
write(STDOUT_FILENO, "$ ", 2);

/* Read the command from the user*/
ssize_t bytes_read = getline(&command, &(size_t){MAX_COMMAND_LENGTH}, stdin);

if (bytes_read == -1)
{
if (feof(stdin))
{
/* Handle end of file (Ctrl+D)*/
printf("\n");
exit(0);
} else {
perror("getline");
exit(1);
}
}

/* Remove the newline character at the end of the command*/
int length = strlen(command);
if (command[length - 1] == '\n')
{
command[length - 1] = '\0';
}

return command;
}
