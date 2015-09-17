/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cho <cho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 16:18:09 by cho               #+#    #+#             */
/*   Updated: 2015/09/16 16:18:11 by cho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

t_dlist 	*ft_get_list(t_dlist *list, char **argv)
{
	argv++;
	while (*argv)
	{
		list = list_append(list, *argv);
		argv++;
	}
	return (list);
}

void 		display_list(t_dlist *list, t_node *position)
{
	t_node 	*node;

	node = list->head;
	while (node != NULL)
	{
		if (node->data == position->data && position == node)
		{
			tputs(tgetstr("us", NULL), 1, tputs_putchar);
			ft_putendl(node->data);
			ft_putchar('\n');
			node = node->next;
		}
		if (node != NULL)
		{
			tputs(tgetstr("me", NULL), 1, tputs_putchar);
			ft_putendl(node->data);
			ft_putchar('\n');
			node = node->next;
		}
	}
}

void		display_video_list(t_dlist *list, t_node *position, t_env *e)
{
	t_node 	*node;

	node = list->head;
	while (node != NULL)
	{
		if (node->data == position->data && position == node)
		{
			if (e->switch_on == 0)
				tputs(tgetstr("so", NULL), 1, tputs_putchar);
			tputs(tgetstr("us", NULL), 1, tputs_putchar);
			ft_putendl(node->data);
			ft_putchar('\n');
			node = node->next;
			position = node;
		}
		if (node != NULL)
		{
			tputs(tgetstr("me", NULL), 1, tputs_putchar);
			ft_putendl(node->data);
			ft_putchar('\n');
			node = node->next;
		}
	}
}

t_node 		*display_first_list(t_dlist *list)
{
	int 	i;
	t_node 	*node;
	t_node 	*position;

	i = 0;
	node = list->head;
	while (node != NULL)
	{
		if (i == 0)
		{
			tputs(tgetstr("us", NULL), 1, tputs_putchar);
			ft_putendl(node->data);
			ft_putchar('\n');
			position = node;
			node = node->next;
			i++;
		}
		if (node != NULL)
		{tputs(tgetstr("me", NULL), 1, tputs_putchar);
		ft_putendl(node->data);
		ft_putchar('\n');
		node = node->next;
		}
	}
	return (position);
}
// tputs(tgetstr("mr", NULL), 1, tputs_putchar); // begin video mode !
// tputs(tgetstr("me", NULL), 1, tputs_putchar); // end all mode !
// tputs(tgetstr("so", NULL), 1, tputs_putchar); // video on !
// tputs(tgetstr("se", NULL), 1, tputs_putchar); // video off !
// tputs(tgetstr("us", NULL), 1, tputs_putchar); // underscore on !
// tputs(tgetstr("ue", NULL), 1, tputs_putchar); // underscore off !
// tgetnum(tgetstr("co", NULL), 1, tputs_putcahr); // get column number !
// tgetnum(tgetstr("li", NULL), 1, tputs_putcahr); // get line number !
// tputs(tgetstr("ve", NULL), 1, tputs_putchar); // normal cursor visible !
// tputs(tgetstr("vi", NULL), 1, tputs_putchar); // cursor invisible !
// tputs(tgetstr("ti", NULL), 1, tputs_putchar); // begin cursor move program !
// tputs(tgetstr("te", NULL), 1, tputs_putchar); // end cursor move program !
