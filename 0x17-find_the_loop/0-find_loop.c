#include "lists.h"

/**
 * find_listint_loop - function that finds the loop in a linked list.
 * 
 * @head: the head of the list to examinate.
 * 
 * Return: the node where the loop is or NULL if there is not lopp.
 */
listint_t *find_listint_loop(listint_t *head)
{
	if (head == NULL || head->next == NULL)
		return (NULL);

	listint_t *turtle, *hare;

	turtle = head;
	hare = head;

	while (hare != NULL)
	{
		turtle = turtle->next;
		hare = hare->next->next;
		if (hare == NULL || hare->next == NULL)
			return (NULL);
		if (hare == turtle)
			return (hare);
	}
	return (NULL);
}
