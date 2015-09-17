/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cho <cho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 16:18:24 by cho               #+#    #+#             */
/*   Updated: 2015/09/16 16:18:24 by cho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	ft_under_first(t_dlist *list)
{
	t_node	*position;
	t_env 	e;

	e.switch_on = 0;
	position = display_first_list(list);
	key_op(list, position, &e);
}

void	ft_under_next(t_dlist *list, t_node *position, t_env *e)
{
	display_list(list, position);
	key_op(list, position, e);
}

void 	ft_video(t_dlist *list, t_node *position, t_env *e)
{
	display_video_list(list, position, e);
	if (e->switch_on == 0)
		e->switch_on = 1;
	else
		e->switch_on = 0;
	key_op(list, position, e);
}
