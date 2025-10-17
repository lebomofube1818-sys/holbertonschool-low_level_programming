#include "main.h"

/**
 * check_palindrome - helper to recursively check palindrome
 * @s: string
 * @start: start index
 * @end: end index
 * Return: 1 if palindrome, 0 if not
 */
int check_palindrome(char *s, int start, int end)
{
    if (start >= end)
        return (1);
    if (s[start] != s[end])
        return (0);
    return (check_palindrome(s, start + 1, end - 1));
}

/**
 * is_palindrome - returns 1 if string is a palindrome
 * @s: string to check
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(char *s)
{
    int len = 0;

    if (!s)
        return (0);

    while (s[len] != '\0')
        len++;

    return (check_palindrome(s, 0, len - 1));
}

