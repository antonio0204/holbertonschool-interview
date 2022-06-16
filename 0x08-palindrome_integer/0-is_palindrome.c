#include "palindrome.h"

int digitPos(unsigned long n, int pos);
double _pow(double base, int exponent);

/**
 * is_palindrome - Finds if a number is palindrome
 * @n: Number to find
 * Return: 1 if @n is palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long n_cpy = n, pow_inc = 1, pow_up = 1;

	if (n < 10)
		return (1);

	while (n_cpy >= 10)
	{
		n_cpy = n_cpy / 10;
		pow_inc++;
	}
	while (pow_inc > pow_up)
	{
		if (digitPos(n, pow_inc) != digitPos(n, pow_up))
			return (0);

		pow_inc--;
		pow_up++;
	}
	return (1);
}

/**
 * digitPos - Get the digit in a position
 * @n: Number to find
 * @pos: Position to find
 * Return: The digit at the position @pos in @n
 */
int digitPos(unsigned long n, int pos)
{
	return ((n / (unsigned long) _pow(10.0, pos - 1)) % 10);
}

/**
 * _pow - Get the pow of a number
 * @base: Base
 * @exponent: Exponent
 * Return: The pow of @base to @exponent
 */
double _pow(double base, int exponent)
{
	double result = 1;

	while (exponent > 0)
	{
		result *= base;
		--exponent;
	}
	return (result);
}
