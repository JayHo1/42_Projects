/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cho <cho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 17:38:13 by cho               #+#    #+#             */
/*   Updated: 2014/11/13 20:50:09 by cho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count(char const *s, char c)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			k++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (k);
}

char	*ft_word(int *i, char const *s, char c)
{
	int		k;
	int		count;
	char	*wrd;

	k = 0;
	count = *i;
	while (s[count] != c && s[count])
		count++;
	wrd = ft_strnew(count - *i);
	if (wrd)
	{
		while (*i < count)
		{
			wrd[k] = s[*i];
			k++;
			*i += 1;
		}
		return (wrd);
	}
	return (0);
}

char	**ft_strsplit(char const *s, char c)
{
	int		*i;
	int		k;
	int		j;
	char	**str;

	j = 0;
	i = &j;
	k = 0;
	str = NULL;
	if (s)
		str = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (str)
	{
		while (k < ft_count(s, c))
		{
			while (s[*i] == c)
				*i += 1;
			if (s[*i] != c && s[*i])
				str[k++] = ft_word(i, s, c);
		}
		str[k] = 0;
		return (str);
	}
	return (0);
}
