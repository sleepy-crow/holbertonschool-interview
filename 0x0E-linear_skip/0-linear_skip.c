#include "search.h"

/**
 * linear_skip - Searches for an element in a skip list.
 *
 * @list: Pointer to the start of a sorted skip list.
 * @value: Value to search in the sorted skip list.
 *
 *
 * Description - This program takes a sorted skip linked list and
 *               searches for a given value, to save time and processing
 *               capacity, the linked list has "express lanes" to further
 *               elements within it.
 *
 * Return: -> The node of the link that contains the searched value on success.
 *         -> NULL if the linked list is NULL or doesn't contain the searched
 *            value.
 *
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *line = list, *exp;
	if (line == NULL)
		return (NULL);

	exp = line->express;

	while (exp)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       exp->index, exp->n);

		if (exp->n >= value)
			break;
		line = exp;
		if (exp->express == NULL)
		{
			while (exp->next)
				exp = exp->next;
			break;
		}
		exp = exp->express;
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
	       line->index, exp->index);
	while (line && line->index <= exp)
	{
		printf("Value checked at index [%lu] = [%d]\n", line->index,
		       line->n);
		if (line->n == value)
		{
			return (line);
		}
		line = line->next;
	}
	return (NULL);
}
