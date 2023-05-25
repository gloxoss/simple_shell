#include "main.h"
/*hundle_ctrl*/
/**
 * handle_sigint - hundles Ctrl-C signal
 * @signsignumal: Argument to the singal function
 * Return : Void
*/
void handle_sigint(int signum)
{
    printf("\nCtrl-C received. Exiting the program.\n");
    exit(0);
}

/**
 * setup_signal_handler -  hundles Ctrl-C signal
 * Return : Void
*/
void setup_signal_handler()
{
    signal(SIGINT, handle_sigint);
}
