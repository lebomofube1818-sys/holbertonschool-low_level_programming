#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - prints the sum of the two diagonals of a square matrix
 * @a: pointer to the first element of the matrix
 * @size: the size of the square matrix
 *
 * Return: void
 */
void print_diagsums(int *a, int size)
{
	int i, sum1 = 0, sum2 = 0;

	for (i = 0; i < size; i++)
	{
		sum1 += a[i * size + i];          /* left-to-right diagonal */
		sum2 += a[i * size + (size - 1 - i)]; /* right-to-left diagonal */
	}

	printf("%d, %d\n", sum1, sum2);
}

