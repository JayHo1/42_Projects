/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cho <cho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 16:18:17 by cho               #+#    #+#             */
/*   Updated: 2015/09/16 16:18:18 by cho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

t_dlist 	*list_new(void)
{
	t_dlist *new_list;
	new_list = (t_dlist *)malloc(sizeof (t_dlist));
	if (new_list != NULL)
	{
		new_list->length = 0;
		new_list->head = NULL;
		new_list->tail = NULL;
	}
	return (new_list);
}

t_dlist		*list_append(t_dlist *list, char *data)
{
	if (list != NULL)
	{
		t_node *node = malloc(sizeof *node);
		if (node != NULL)
		{
			node->data = data;
			node->next = NULL;
			if (list->tail == NULL)
			{
				node->prev = NULL;
				list->head = node;
				list->tail = node;
			}
			else
			{
				list->tail->next = node;
				node->prev = list->tail;
				list->tail = node;
			}
			list->length++;
		}
	}
	return (list);
}

t_dlist 	*list_prepend(t_dlist *list, char *data)
{
	if (list != NULL)
	{
		t_node *node = malloc(sizeof *node);
		if (node != NULL)
		{
			node->data = data;
			node->prev = NULL;
			if (list->tail == NULL)
			{
				node->next = NULL;
				list->head = node;
				list->tail = node;
			}
			else
			{
				list->head->prev = node;
				node->next = list->head;
				list->head = node;
			}
			list->length++;
		}
	}
	return (list);
}
