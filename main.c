#include "main.c"

int main(void) {
   signal(SIGINT, handle_ctrl_c);

    while (1)
    {
        prompt();
    }

    return 0;
}

