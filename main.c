#include "main.c"

int main(int argc, char **argv, char **envp) {
  int fd;

  if (argc == 2) {
    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
      if (errno == EACCES) {
        exit(126);
      } else if (errno == ENOENT) {
        exit(127);
      } else {
        return EXIT_FAILURE;
      }
    }
  } else {
    fd = STDIN_FILENO;
  }

  setup_signal_handler();

  prompt(argv, envp);

  if (fd != STDIN_FILENO) {
    close(fd);
  }

  return 0;
}

