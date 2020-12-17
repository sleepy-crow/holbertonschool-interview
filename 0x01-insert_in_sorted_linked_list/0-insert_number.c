#include "lists.h"

/**
 * insert_node - Inserts a node in a sorted linked list
 *
 * @head: First node on the linked list
 * @number: Number to insert in the list
 *
 *
 * Description - This function takes a number and inserts it in the right
 *               position in the given linked list. It returns a pointer
 *               to the newly created node or Null if anything goes wrong.
 *
 *
 * Return: -> Pointer to the newly created node in the list.
 *         -> Null if there is an error.
 *
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *nod = malloc(sizeof(listint_t));
	listint_t *cur = *head;

	if (nod == NULL)
		return (NULL);
	nod->n = number;
	if (*head == NULL)
	{
		nod = add_nodeint_end(head, number);
		*head = nod;
		return (nod);
	}
	if (cur->n < nod->n && cur->next == NULL)
	{
		cur->next = nod;
		nod->next = NULL;
		*head = nod;
		return (nod);
	}
	while (cur->next != NULL)
	{
		if (cur->next->n > nod->n)
		{
			nod->next = cur->next;
			cur->next = nod;
			return (nod);
		}
		cur = cur->next;
	}
	if (cur->next == NULL)
	{
		cur->next = nod;
		nod->next = NULL;
		return (nod);
	}
	if (cur->next->n > nod->n)
		{
			nod->next = cur->next;
			cur->next = nod;
		}
		return (nod);
}
