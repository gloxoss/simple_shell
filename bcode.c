/**
 * _strlen - Computes the length of a string.
 * @str: The input string.
 *
 * Return: The length of the string.
 */
size_t _strlen(const char *str)
{
size_t len = 0;

while (str[len])
len++;

return (len);
}
