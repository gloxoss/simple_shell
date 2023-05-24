#include "main.h"
/**
 * exit -  exits the shell
 * Return: Void
 */
void exit_shell(void)
{
write(1, "Exiting...\n", 11);
exit(0);
}
