#include "lists.h"

/**
 *check_cycle - function that checks if alinked list
 *				is in a clicle
 *
 *@list: the list to check
 *
 *Return: 0 if there is no cycle, 1 if there is a cycle
 */

int check_cycle(listint_t *list)
{
	listint_t *tortoise, *hare;

	tortoise = malloc(sizeof(listint_t));
	if (tortoise == NULL)
		return (1);
	
	hare = malloc(sizeof(listint_t));
	if (hare == NULL)
		return (1);

	tortoise = hare = list;
	while (hare != NULL)
	{
		if (hare->next == NULL)
			return (0);
		hare = hare->next->next;
		tortoise = tortoise->next;
		if (hare == tortoise)
			return (1);
	}
	return (0);
}