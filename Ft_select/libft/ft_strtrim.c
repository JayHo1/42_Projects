/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cho <cho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 09:10:25 by cho               #+#    #+#             */
/*   Updated: 2014/11/12 16:58:16 by cho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check(int c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	else
		return (0);
}

char	*ft_strtrim(char const *s)
{
	int		k;
	int		c;
	char	*str;

	if (s)
	{
		k = 0;
		c = 0;
		str = ft_strnew(ft_strlen(s));
		while (*s)
		{
			if (ft_check(*s) && !c)
				s++;
			else
			{
				c = 1;
				str[k++] = *s;
				s++;
			}
		}
		while (ft_check(str[--k]))
			str[k] = '\0';
		return (str);
	}
	return (NULL);
}
