#include "main.h"

/**
 * rev_string - reverses a string
 * @s: pointer to the string to reverse
 *
 * Return: void
 */
void rev_string(char *s)
{
	int i;
	int j;
	char tmp;

	i = 0;
	while (s[i] != '\0')
		i++;

	if (i <= 1)
		return;

	j = i - 1;
	i = 0;

	while (i < j)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i++;
		j--;
	}
}

