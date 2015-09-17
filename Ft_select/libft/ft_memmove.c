/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cho <cho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:59:48 by cho               #+#    #+#             */
/*   Updated: 2014/11/06 17:31:32 by cho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *tmp_dst;

	if (!dst || !src)
		return (NULL);
	tmp_dst = (unsigned char*)malloc(sizeof(tmp_dst) * len);
	ft_memcpy(tmp_dst, src, len);
	ft_memcpy(dst, tmp_dst, len);
	free(tmp_dst);
	return (dst);
}
