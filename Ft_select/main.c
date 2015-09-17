/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cho <cho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 16:18:36 by cho               #+#    #+#             */
/*   Updated: 2015/09/16 16:18:37 by cho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

int 		main(int argc, char **argv)
{
	if (argc > 1)
	{
		t_termios 	term;
		t_dlist		*list;
		
		list = list_new();
		ft_get_list(list, argv);
		I_canon(&term);
		ft_under_first(list);
	}
	else
		printf("ERROR\n");
	return (0);
}
