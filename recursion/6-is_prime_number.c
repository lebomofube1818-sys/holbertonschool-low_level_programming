#include "main.h"

/**
 * is_prime_helper - checks recursively if n is divisible
 * @n: number to check
 * @div: current divisor
 *
 * Return: 1 if prime, 0 if divisible
 */
int is_prime_helper(int n, int div)
{
	if (div * div > n)
		return (1);

	if (n % div == 0)
		return (0);

	return (is_prime_helper(n, div + 1));
}

/**
 * is_prime_number - returns 1 if n is prime, 0 otherwise
 * @n: number to check
 *
 * Return: 1 if prime, 0 if not
 */
int is_prime_number(int n)
{
	if (n < 2)
		return (0);

	return (is_prime_helper(n, 2));
}

