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
char *full_path = path(command);
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
} else if (pid > 0)
{
waitpid(pid, &status, 0);
}
}

