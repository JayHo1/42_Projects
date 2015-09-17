/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cho <cho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 16:18:48 by cho               #+#    #+#             */
/*   Updated: 2015/09/16 16:18:49 by cho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H

# include <termios.h>
# include <term.h>
# include <unistd.h>
# include <stdlib.h>
# include <curses.h>
# include "libft/libft.h"

# define BUFF_SIZE	4096
# define ESCAPE	buffer[0] == 27 && buffer[1] == 0 && buffer[2] == 0
# define SPACE	buffer[0] == 32 && buffer[1] == 0 && buffer[2] == 0
# define UP		buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 65
# define LEFT	buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 68
# define RIGHT	buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 67
# define DOWN	buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 66

typedef struct termios t_termios;

typedef struct 	node
{
	char 		*data;
	struct node *next;
	struct node *prev;
}				t_node;

typedef struct 	dlist
{
	size_t 		length;
	struct node *tail;
	struct node *head;
}				t_dlist;

typedef struct 	s_env
{
	int 	switch_on;
	int 	off;
}				t_env;

t_dlist 	*list_new(void);
t_dlist		*list_append(t_dlist *list, char *data);
t_dlist 	*list_prepend(t_dlist *list, char *data);
t_dlist 	*ft_get_list(t_dlist *list, char **argv);
void 		display_list(t_dlist *list, t_node *node);
t_node 		*display_first_list(t_dlist *list);
void		display_video_list(t_dlist *list, t_node *position, t_env *e);
void 		ft_video(t_dlist *list, t_node *position, t_env *e);
void		ft_under_first(t_dlist *list);
void		ft_under_next(t_dlist *list, t_node *position, t_env *e);
void		key_op2(t_dlist *list, t_node *position, t_env *e, char *buffer);
int			I_canon(t_termios *term);
int     	key_op(t_dlist *list, t_node *position, t_env *e);
int 		tputs_putchar(int c);

#endif
