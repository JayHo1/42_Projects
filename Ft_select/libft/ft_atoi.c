/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cho <cho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:39:47 by cho               #+#    #+#             */
/*   Updated: 2014/11/10 17:50:45 by cho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_atoi(const char *str)
{
	unsigned int	i;
	int				signe;
	int				value;

	i = 0;
	value = 0;
	while (*str == ' ' || *str == '\t' || *str == '\f' || *str == '\v'
		|| *str == '\r' || *str == '\n')
		str++;
	signe = (*str == '-' ? -1 : 1);
	if (*str == '-' || *str == '+')
		str++;
	while (*str == '0')
		str++;
	while (ft_isdigit(*str) && *str)
	{
		i = (int)(*str - '0');
		value = (value * 10) + i;
		str++;
	}
	return (value * signe);
}
