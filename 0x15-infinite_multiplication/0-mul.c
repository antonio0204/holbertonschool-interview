#include "holberton.h"

/**
 * _isdigit - check if a string is a digit
 * Description - This function is to check if a string is a digit
 * @n: Sring to guess if is an uppercase character
 * Return: 1 if n is a digit, 0 otherwise
 */
int _isdigit(char *n)
{
	int i;

	i = 0;
	while (*(n + i) != '\0')
	{
		if (*(n + i) < '0' || *(n + i) > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * _strlen - Return the len of a string
 * Description: This function shows the length of a given string
 * @s: Pointer that contains the string
 * Return: @s len
 */
int _strlen(const char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

/**
 * main - the entry point
 * @argc: Number of arguments
 * @argv: Arguments to multiply
 * Return: return 0, 98 otherwise and prints Error
 */
int main(int argc, char *argv[])
{
	int p, res, len, n1, n2, i, j;
	int *total;

	if (argc < 3 || argc > 3 || !(_isdigit(argv[1])) || !(_isdigit(argv[2])))
		puts("Error"), exit(98);
	if (argv[1][0] == '0' || argv[2][0] == '0')
	{
		printf("0\n");
		return (0);
	}
	n1 = _strlen(argv[1]), n2 = _strlen(argv[2]);
	len = n1 + n2;
	total = calloc(len, sizeof(int *));
	if (total == NULL)
		puts("Error"), exit(98);
	for (i = (n2 - 1); i > -1; i--)
	{
		res = 0;
		for (j = (n1 - 1); j > -1; j--)
		{
			p = (argv[2][i] - '0') * (argv[1][j] - '0');
			res =  (p / 10);
			total[(i + j) + 1] += (p % 10);
			if (total[(i + j) + 1] > 9)
			{
				total[i + j] += total[(i + j) + 1] / 10;
				total[(i + j) + 1] = total[(i + j) + 1] % 10;
			}
			total[(i + j)] += res;
		}
	}
	if (total[0] == 0)
		i = 1;
	else
		i = 0;
	for (; i < len; i++)
		printf("%d", total[i]);
	printf("\n");
	free(total);
	return (0);
}
