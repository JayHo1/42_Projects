/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cho <cho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 16:20:04 by cho               #+#    #+#             */
/*   Updated: 2014/11/12 16:16:05 by cho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			str[i] = (f)(i, str[i]);
			i++;
		}
		return (str);
	}
	return (NULL);
}
