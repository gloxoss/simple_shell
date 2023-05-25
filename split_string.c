#include "main.h"

/**
 * split_string -  splits a string into an array of strings
 * @text: Pointer to the string
 * Return: Array of strings
 */
char **split_string(char *text)
{
int index = 0;
int is_token = 0;
char **tokens = malloc(100 * sizeof(char *));
    
if (!tokens)
{
perror("Failed to allocate memory");
exit(EXIT_FAILURE);
}
char *token = strtok(text, " \t\n");
    
while (token != NULL)
{
if (is_token == 0 && token[0] == ' ')
{
token = strtok(NULL, " \t\n");
continue;
}
        
tokens[index] = token;
index++;
is_token = 1;
token = strtok(NULL, " \t\n");
}
    
tokens[index] = NULL;
    
return (tokens);
}

