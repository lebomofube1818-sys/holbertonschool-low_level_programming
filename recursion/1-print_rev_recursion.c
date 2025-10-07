#include "main.h"

/**
 * _print_rev_recursion - prints a string in reverse
 * @s: string to print
 *
 * Description: prints each character in reverse order using recursion.
 * Only _putchar is used, no loops or static variables.
 */
void _print_rev_recursion(char *s)
{
    if (*s == '\0')
        return;

    _print_rev_recursion(s + 1);
    _putchar(*s);
}

