#include "main.h"
/**
 * prompt -  start prompt
 * Return: void
 */
char *prompt()
{
size_t max_length = MAX_COMMAND_LENGTH;
char *command = NULL;
ssize_t bytes_read;
int length;

command = malloc(max_length * sizeof(char));
if (!command) {
perror("Failed to allocate memory");
exit(EXIT_FAILURE);
}
bytes_read = getline(&command, &max_length, stdin);
/* Display the prompt*/
write(STDOUT_FILENO, "$ ", 2);

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
length = strlen(command);
if (command[length - 1] == '\n')
{
command[length - 1] = '\0';
}

return command;
}
