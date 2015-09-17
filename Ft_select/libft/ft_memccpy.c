/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cho <cho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:48:03 by cho               #+#    #+#             */
/*   Updated: 2014/11/06 16:58:13 by cho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			x;
	unsigned char			*tmp_dst;
	unsigned const char		*tmp_src;

	x = (unsigned char)c;
	tmp_dst = dst;
	tmp_src = src;
	while (n--)
	{
		if (*tmp_src == x)
		{
			*tmp_dst++ = *tmp_src++;
			return (tmp_dst);
		}
		*tmp_dst++ = *tmp_src++;
	}
	return (NULL);
}
