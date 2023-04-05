#include "lists.h"
/**
 * free_listint_safe - frees a listint_t linked list
 * @h: double pointer to start of the list
 *
 * Return: number of nodes in the list
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *goat = *h, *hare = *h, *temp, *poi;
	size_t isLoop = 0, nodes = 0;

	if (!(*h))
		return (nodes);
	while (goat && hare && hare->next)
	{
		/* Detecting if linked list is looped */
		goat = goat->next, hare = hare->next->next;
		if (goat == hare)
		{
			isLoop = 1;
			break;
		}
	}
	if (isLoop) /* Removing the loop*/
	{
		if (*h == hare) /* cater for two elements list*/
			hare->next->next = NULL;
		else
		{
			goat = *h;
			while (goat != hare)
			{
				goat = goat->next;
				poi = hare;
				hare = hare->next;
			}
			poi->next = NULL;
		}
	}
	while (*h)
	{
		temp = *h;
		nodes += 1;
		*h = temp->next;
		free(temp);
	}

	return (nodes);
}
