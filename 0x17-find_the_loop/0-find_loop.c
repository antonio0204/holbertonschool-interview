#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: Head of the linked list
 * Return: The address of the node where the loop starts
 * or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *har, *tor;

	tor = head;
	har = head;

	while (tor && har && har->next)
	{
		tor = tor->next;
		har = har->next->next;

		if (tor == har)
		{
			tor = head;
			while (tor && har)
			{
				if (tor == har)
					return (tor);
				tor = tor->next;
				har = har->next;
			}
		}
	}
	return (NULL);
}
