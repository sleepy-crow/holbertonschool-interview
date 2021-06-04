#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * find_listint_loop - function that finds the loop in a linked list.
 *
 * @head: the head of the list to examinate.
 *
 * Return: the node where the loop is or NULL if there is not loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *hare, *turtle;

	if (head == NULL)
		return (NULL);

	turtle = head->next;
	hare = turtle->next;

	while (turtle && hare && hare->next)
	{
		if (turtle == head || hare == head)
			return (head);

		if (hare == turtle && hare != head)
		{
			head = head->next;
			hare = head;
			turtle = head;
		}
		turtle = turtle->next;
		hare = hare->next->next;
	}
	return (NULL);
}
