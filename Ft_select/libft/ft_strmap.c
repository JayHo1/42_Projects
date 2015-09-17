/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cho <cho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 14:42:09 by cho               #+#    #+#             */
/*   Updated: 2014/11/12 17:44:34 by cho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		len;
	char	*str;

	if (s && f)
	{
		i = 0;
		len = ft_strlen(s);
		str = ft_strdup(s);
		if (!str)
			return (NULL);
		while (i < len)
		{
			str[i] = (f)(str[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
