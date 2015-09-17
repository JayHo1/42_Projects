/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cho <cho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 17:09:29 by cho               #+#    #+#             */
/*   Updated: 2014/11/12 16:17:17 by cho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	int		k;
	char	*str;

	if (s)
	{
		i = 0;
		k = ft_strlen(s);
		str = ft_strnew(len);
		if (k == 0 && start > len)
			return (NULL);
		while (s[start] != '\0' && i < len)
		{
			str[i] = s[start];
			start++;
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
