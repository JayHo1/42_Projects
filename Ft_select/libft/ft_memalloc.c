/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cho <cho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 19:03:21 by cho               #+#    #+#             */
/*   Updated: 2014/11/07 19:26:45 by cho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memalloc(size_t size)
{
	unsigned int	i;
	void			*mem;
	char			*str;

	i = 0;
	mem = (void *)malloc(size);
	str = (char *)mem;
	if (mem != NULL)
	{
		while (size > 0)
		{
			str[i] = 0;
			i++;
			size--;
		}
	}
	return (mem);
}
