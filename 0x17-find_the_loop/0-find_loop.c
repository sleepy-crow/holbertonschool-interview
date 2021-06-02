#include "lists.h"

/**
 * is_a_loop_there - function that checks if there is a loop
 * in the list.
 *
 * @head: the head of the list to examinate.
 *
 * Return: 0 if there is no loop and 1 if there is a loop
 */
int is_a_loop_there(listint_t *head)
{
	listint_t *turtle, *hare;

	turtle = head;
	hare = head;

	while (hare != NULL)
	{
		turtle = turtle->next;
		hare = hare->next->next;
		if (hare == NULL || hare->next == NULL)
			return (0);
		if (hare == turtle)
			return (1);
	}
	return (0);
}

/**
 * some_where_over_the_rainbow - function that finds
 * the node where the loop starts.
 *
 * @head: looped linked list.
 *
 * Return: the node where the loop begins
 */
listint_t *some_where_over_the_rainbow(listint_t *head)
{
	listint_t *turtle, *hare;

	turtle = head;
	hare = head;

	while (hare != NULL)
	{
		turtle = turtle->next;
		hare = hare->next->next;
		if (hare == turtle)
		{
			turtle = head;
			while (1)
			{
				turtle = turtle->next;
				hare = hare->next;
				if (hare == turtle)
					return (turtle);
			}
		}
	}
	return (NULL);
}
/**
 * find_listint_loop - function that finds the loop in a linked list.
 *
 * @head: the head of the list to examinate.
 *
 * Return: the node where the loop is or NULL if there is not loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	if (head == NULL || head->next == NULL)
		return (NULL);

	int looper = is_a_loop_there(head);

	if (looper == 0)
	{
		return (NULL);
	}
	else
	{
		return (some_where_over_the_rainbow(head));
	}
	return (NULL);
}
