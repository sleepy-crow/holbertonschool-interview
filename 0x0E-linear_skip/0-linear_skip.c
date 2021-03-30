#include "search.h"

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
