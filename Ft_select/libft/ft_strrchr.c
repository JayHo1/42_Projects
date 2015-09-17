/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cho <cho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:35:22 by cho               #+#    #+#             */
/*   Updated: 2014/11/09 16:35:13 by cho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	char *dst;

	dst = (char *)s;
	dst = dst + ft_strlen(s);
	while (*dst != (char)c && dst != s)
		dst--;
	if (*dst == (char)c)
		return ((char *)dst);
	return (NULL);
}
