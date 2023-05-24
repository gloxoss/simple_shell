int main() {
  char *line = NULL;
  size_t len = 0;
  int n;

  while (1) {
    prompt();

    n = getline(&line, &len, stdin);
    if (n == -1) {
      if (feof(stdin)) {
        break;
      } else {
        perror("getline");
        exit(1);
      }
    }

    strip(line);

    // If the line is empty, do nothing.
    if (strlen(line) == 0) {
      continue;
    }

    // Parse the line into commands and arguments.
    char **arguments = parse(line);

    // Execute the command.
    if (arguments != NULL) {
      execute(arguments[0], arguments);
    }

    free(arguments);
  }

  return 0;
}
