#include "main.h"

/**
  * _atoi - convert str to int
  * @s: the string
  *
  * Return: the number in integer
  */
int _atoi(char *s)
{
unsigned int num = 0;
int i = 0;
int sign = 1;

while (*(s + i))
{
if (*(s + i) == '-')
sign *= -1;
else if (*(s + i) >= '0' && *(s + i) <= '9')
num = (num * 10) + (*(s + i) - '0');
else if (num > 0)
break;
i++;
}
return (num * sign);
}



/**
 * is_num - Checks if a string represents a numeric value
 * @str: The string to check
 * Return: True if the string is numeric, false otherwise
 */
bool is_num(const char *str)
{
int i;

if (str == NULL || *str == '\0')
return false;

for (i = 0; str[i] != '\0'; i++)
{
if (str[i] < '0' || str[i] > '9')
return false;
}

return true;
}
#include <stdbool.h>

/**
 * strncmp - Function that compares two strings up to a specified number of characters
 * @s1: Pointer to the first string
 * @s2: Pointer to the second string
 * @n: Number of characters to compare
 * Return:
 *   - an integer less than, equal to, or greater than zero if the first `n` characters
 *     of `s1` are respectively less than, equal to, or greater than the first `n` characters of `s2`.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
size_t i;

for (i = 0; i < n; i++)
{
if (s1[i] == '\0' || s1[i] != s2[i])
return (unsigned char)s1[i] - (unsigned char)s2[i];
}
return 0;
}

/**
 * _strcmp - compares two strings.
 * @s1: First string
 * @s2: Second string
 * Return: s1[i] - s2[i]
 */


int _strcmp(char *s1, char *s2)
{
int i = 0;

while (s1[i] == s2[i])
{
if (s1[i] == '\0')
{
return (0);
}
i++;

}
return (s1[i] - s2[i]);
}


/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}
