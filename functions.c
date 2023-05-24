#include "main.h"

/**
 * prompt -  start prompt
 * Return: void
 */
void prompt()
{
write(1, "hsh> ", 5);
}
/**
 * exit -  exits the shell
 * Return: Void
 */
void exit() {
write(1, "Exiting...\n", 11);
exit(0);
}
/**
 * Executes -  execute the code
 *
 * @command :  The command to execute.
 * @arguments The arguments to the command.
 *
 * Return :  void
 */
void execute(char *command, char **arguments)
{
pid_t pid = fork();

if (pid == 0)
{
char *path = getenv("PATH");
char *full_path = NULL;
size_t len = strlen(command);

/* Split the PATH environment variable into an array of strings.*/
char **paths = malloc(sizeof(char *) * (strlen(path) / 2 + 1));
if (paths == NULL)
{
return;
}

int i = 0;
char *token = strtok(path, ":");
while (token != NULL) {
paths[i] = token;
token = strtok(NULL, ":");
i++;
}

    /* Iterate through the array of paths and try to find the command.*/
for (i = 0; paths[i] != NULL; i++)
{
size_t path_len = strlen(paths[i]);
char *full_path_temp = malloc(sizeof(char *) * (len + path_len + 2));
if (full_path_temp == NULL)
{
return;
}

strcpy(full_path_temp, paths[i]);
strcat(full_path_temp, "/");
strcat(full_path_temp, command);

/* Check if the command exists in the current path.*/
int status = access(full_path_temp, F_OK);
if (status == 0) {
full_path = full_path_temp;
break;
}

free(full_path_temp);
}

/* Free the array of paths.*/
free(paths);

/* Execute the command.*/
if (full_path == NULL)
{
write(2, "Command not found: %s\n", command);
exit(1);
}

int status = execvp(full_path, arguments);
if (status == -1)
{
perror(command);
exit(1);
}
}

/* If the child process was not created successfully, wait for it to exit.*/
else if (pid > 0)
{
waitpid(pid, &status, 0);
}
}

/**
 * strip - strips the newline character from the end of the line that was read
 * Return :  void
 */
void strip(char *str)
{
if (str[strlen(str) - 1] == '\n')
{
str[strlen(str) - 1] = '\0';
}
}
/**
 * parse -  parses the line into commands and arguments
 * Return :  **char
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
