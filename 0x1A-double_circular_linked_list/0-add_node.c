#include "list.h"

/**
 * add_node_end - Add a new node to the end of a
 * double circular linked list
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *neo = malloc(sizeof(List));
	List *tmp = *list;

	if(neo == NULL)
		return (NULL);

	neo->str = str;
	if(tmp == NULL)
	{
		*list = neo;
		neo->prev = NULL;
		neo->next = NULL;
		return (neo);
	}
	else if (tmp != NULL && tmp->prev == NULL)
	{
		neo->next = *list;
		neo->prev = *list;
		tmp->next = neo;
		tmp->prev = neo;
		return (neo);
	}
	else
	{
		neo->next = tmp;
		neo->prev = tmp->prev;
		tmp->prev->next = neo;
		tmp->prev = neo;
		return (neo);
	}
	return (NULL);
}

/**
 * add_node_begin - Add a new node to the beginning of a
 * double circular linked list
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *neob = add_node_end(list, str);
	*list = neob;
	return (neob);
}
