/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cho <cho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 16:03:12 by cho               #+#    #+#             */
/*   Updated: 2015/09/17 16:03:13 by cho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

int     	key_op(t_dlist *list, t_node *position, t_env *e)
{
  	char 		buffer[3];

	while (1)
	{
		ft_bzero(buffer, 3);
		read(0, buffer, 3);
		if (UP)
		{
			tputs(tgetstr("cl", NULL), 0, tputs_putchar);
			if (position->prev == NULL)
				ft_under_next(list, list->tail, e);
			else
				ft_under_next(list, position->prev, e);
		}
		if (DOWN)
		{
			tputs(tgetstr("cl", NULL), 0, tputs_putchar);
			if (position->next == NULL)
				ft_under_next(list, list->head, e);
			else
				ft_under_next(list, position->next, e);
		}
		if ((SPACE) || (ESCAPE))
			key_op2(list, position, e, buffer);
	}
	return (0);
}

void		key_op2(t_dlist *list, t_node *position, t_env *e, char *buffer)
{
	if (SPACE)
	{
		if (e->switch_on == 0)
		{
			tputs(tgetstr("cl", NULL), 0, tputs_putchar);
			ft_video(list, position, e);
		}
		else
		{
			tputs(tgetstr("cl", NULL), 0, tputs_putchar);
			ft_video(list, position, e);
		}
	}
	if (ESCAPE)
		exit(0);
}

int			I_canon(t_termios *term)
{
	char 	*name_term;

	name_term = getenv("TERM");
	if (name_term == NULL)
		return (-1);
	if (tgetent(NULL, name_term) != 1)
		return (-1);
	if (tcgetattr(0, term) == -1)
		return (-1);
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, term) == -1)
		return (-1);
	tputs(tgetstr("cl", NULL), 0, tputs_putchar);
	return (0);
}