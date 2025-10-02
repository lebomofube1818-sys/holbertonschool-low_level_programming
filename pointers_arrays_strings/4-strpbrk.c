#include "main.h"

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: the string to search
 * @accept: the set of bytes to look for
 *
 * Return: pointer to the byte in s that matches one of the bytes in accept,
 *         or NULL (0) if no such byte is found
 */
char *_strpbrk(char *s, char *accept)
{
	unsigned int i;

	while (*s)
	{
		for (i = 0; accept[i] != '\0'; i++)
		{
			if (*s == accept[i])
				return (s);
		}
		s++;
	}
	return (0);
}

