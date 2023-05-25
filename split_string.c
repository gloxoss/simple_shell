#include "main.h"
/**
 * split_string -  splits a string into tokens
 * @line: Pointer to the string
 * Return: Array of tokens
 */

char **split_string(char *line) {
  char **tokens = NULL;
  size_t n = 0;
  size_t i;

  // Count the number of tokens.
  for (i = 0; line[i]; i++) {
    if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n') {
      n++;
    }
  }

  // Allocate memory for the tokens.
  tokens = malloc(sizeof(char *) * (n + 1));
  if (tokens == NULL) {
    return NULL;
  }

  // Populate the tokens array.
  i = 0;
  tokens[i] = strtok(line, " \t\n");
  while (tokens[i] != NULL) {
    i++;
    tokens[i] = strtok(NULL, " \t\n");
  }

  // Return the tokens array.
  return tokens;
}
