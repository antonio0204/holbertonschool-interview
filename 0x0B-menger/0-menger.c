#include "menger.h"

/**
* menger - This function prints a menger sponge
* @level: sponge level
* Return: nothing
*/
void menger(int level)
{
	int x = 0, y = 0, s_sponge = pow(3, level), space = 0, subx = 0, suby = 0;

	for (x = 0; x < s_sponge; x++)
	{
		for (y = 0; y < s_sponge; y++)
		{
			for (subx = x, suby = y, space = 0; subx || suby; subx /= 3, suby /= 3)
				if (subx % 3 == 1 && suby % 3 == 1)
					space = 1;
			printf("%c", space ? ' ' : '#');
		}
		printf("\n");
	}
}
