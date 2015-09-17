/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cho <cho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 20:29:26 by cho               #+#    #+#             */
/*   Updated: 2014/11/12 18:39:00 by cho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *meule_de_foin, const char *aiguille, size_t n)
{
	unsigned int a;
	unsigned int b;

	a = 0;
	b = 0;
	if (!aiguille)
		return ((char*)meule_de_foin);
	while (meule_de_foin[a] && a < n)
	{
		while (aiguille[b] && aiguille[b] == meule_de_foin[a + b] && a + b < n)
			b++;
		if (aiguille[b] == '\0' || n == a)
			return ((char*)&meule_de_foin[a]);
		b = 0;
		a++;
	}
	return (NULL);
}
