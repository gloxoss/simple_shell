/**
 * strip - strips the newline character from the end of the line that was read
 *@str : string
 * Return :  void
 */
void strip(char *str)
{
if (str[strlen(str) - 1] == '\n')
{
str[strlen(str) - 1] = '\0';
}
}
