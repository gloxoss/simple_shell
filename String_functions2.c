#include "main.h"
/**
 * _strcpy - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
int i = 0;

if (dest == src || src == 0)
return (dest);
while (src[i])
{
dest[i] = src[i];
i++;
}
dest[i] = 0;
return (dest);
}

/**
 * _strlen - returns the length of a string
 * @s: the pointer of the string
 *
 * Return: len
 */

int _strlen(char *s)
{
len = 0;
int i = 0;

while (*(s + i) != '\0')
{
len++;
i++;
}

return (len);
}
