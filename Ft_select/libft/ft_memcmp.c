/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cho <cho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:42:20 by cho               #+#    #+#             */
/*   Updated: 2014/11/06 19:17:40 by cho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *tmp_s1;
	const unsigned char *tmp_s2;

	tmp_s1 = (unsigned char*)s1;
	tmp_s2 = (unsigned char*)s2;
	if (!tmp_s1 || !tmp_s2)
		return (0);
	while (n--)
	{
		if (*tmp_s1 != *tmp_s2)
			return ((unsigned char)*tmp_s1 - (unsigned char)*tmp_s2);
		tmp_s1++;
		tmp_s2++;
	}
	return (0);
}
