/**
 * execute -  execute the code
 *
 * @command :  The command to execute.
 * @arguments : The arguments to the command.
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
for (char *dir in paths)
{
full_path = malloc(strlen(dir) + strlen(command) + 2);
if (full_path == NULL)
{
return;
}
strcpy(full_path, dir);
strcat(full_path, "/");
strcat(full_path, command);
if (access(full_path, F_OK) == 0)
{
break;
}
free(full_path);
}
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
else if (pid > 0)
{
waitpid(pid, &status, 0);
}
}
