#include "main.h"

/**
	* _puts_recursion - prints a string followed by a new line
	* @s: pointer to the string to print
	*
	* Description: This function prints a string recursively,
	* using _putchar to print each character.
	*/
void _puts_recursion(char *s)
{
	if (*s == '\0')
	{
	_putchar('\n');
	return;
	}

	_putchar(*s);
	_puts_recursion(s + 1);
}

