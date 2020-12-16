#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_node - this function creates a new node
 * @head: the head of list
 * @number: the int value of the new node
 * Return: return the new node
 */

listint_t *insert_node(listint_t **head, int number)
{

	listint_t *neo = malloc(sizeof(listint_t));
	listint_t *cur;

	if (neo == NULL)
		return (NULL);
	neo->n = number;
	if (head == NULL)
	{
		neo = add_nodeint_end(head, number);
		*head = neo;
		return (neo);
	}
	cur = *head;
	if (cur == NULL)
	{
		neo->next = NULL;
		return (neo);
	}
	if (cur->n > number)
	{
		neo->next = cur;
		*head = neo;
		return (neo);
	}

	while (cur->next->n < number && cur->next->next != NULL)
	{
		cur = cur->next;
	}
	if (cur->next !=  NULL)
		cur = cur->next;
	if (cur->n < number)
		add_nodeint_end(head, number);
	else
	{
		neo->next = cur->next;
		cur->next = neo;
	}

	return (neo);
}

