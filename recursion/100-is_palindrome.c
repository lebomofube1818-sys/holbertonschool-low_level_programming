#include "main.h"

/**
	* _strlen_recursion - returns the length of a string
	* @s: string to measure
	* Return: length of string
	*/
int _strlen_recursion(char *s)
{
	if (*s == '\0')
	return (0);
	return (1 + _strlen_recursion(s + 1));
}

/**
	* check_palindrome - helper to check palindrome recursively
	* @s: string to check
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
	* is_palindrome - returns 1 if string is a palindrome, 0 if not
	* @s: string to check
	* Return: 1 if palindrome, 0 if not
	*/
int is_palindrome(char *s)
{
	if (*s == '\0')
	return (1);

	return (check_palindrome(s, 0, _strlen_recursion(s) - 1));
}

