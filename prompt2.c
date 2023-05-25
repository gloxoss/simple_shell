#include "main.h"
/**
 * prompt2 -  start prompt
 * Return: void
 */
int prompt2()
{
char *prompt = "simple_shell> ";

char *input = NULL;
pid_t pid;
int status;
int exit_status = 0;

for (;;) {
printf("%s", prompt);

fgets(input, 100, stdin);

if (input[strlen(input) - 1] == '\n')
{
input[strlen(input) - 1] = '\0';
}

if (strlen(input) == 0)
{
break;
}

pid = fork();
if (pid == 0) {
status = execvp(input, NULL);
if (status == -1)
{
perror("execvp");
exit(1);
}
} else if (pid < 0)
{
perror("fork");
exit(1);
} else {
wait(&exit_status);
}
}
return exit_status;
}
