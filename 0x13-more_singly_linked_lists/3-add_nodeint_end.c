#include "lists.h"

/**
 * add_nodeint_end - Adds a new node at the
 *                   end of a listint_t list.
 * @head: A pointer to the address of the
 *        head of the listint_t list.
 * @n: The integer for the new node to contain.
 *
 * Return: If the function fails - NULL.
 *         Otherwise - the address of the new element.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *know, *last;

	know = malloc(sizeof(listint_t));
	if (know == NULL)
		return (NULL);

	know->n = n;
	know->next = NULL;

	if (*head == NULL)
		*head = know;

	else
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;
		last->next = know;
	}

	return (*head);
}
