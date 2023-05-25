#include "main.h"

/**
 * split_string -  splits a string into an array of strings
 * @text: Pointer to the string
 * Return: Array of strings
 */
char **split_string(char *text)
{
char **values = malloc(100 * sizeof(char *));
if (!values)
{
perror("Failed ...");
exit(EXIT_FAILURE);
}
int index = 0, is_token = 0;
char *token = strtok(text, " \t\n");
if (token == NULL)
{
free(values);
return NULL;
}
while (token != NULL)
{
if (is_token == 0 && token[0] == ' ')
{
token = strtok(NULL, " \t\n");
continue;
}
values[index++] = token;
is_token = 1;
token = strtok(NULL, " \t\n");
}
values[index] = NULL;
return values;
}
