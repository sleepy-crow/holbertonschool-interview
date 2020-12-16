#include "lists.h"

listint_t *insert_node(listint_t **head, int number)
{
    
	listint_t *neo, *cur = *head;

	neo = malloc(sizeof(listint_t));

	if (neo == NULL)
		return (NULL);

	neo->n = number;
	if (neo->n < cur->n)
	{
		neo->next = cur;
		*head = neo;
	}
	else
	{
		while (1)
		{
			if (neo->n < cur->next->n || cur->next == NULL)
			{
				neo->next = cur->next;
				cur->next = neo;
				break;
			}
			else
			{
				cur = cur->next;
			}
		}
	}
	return (neo);
}

