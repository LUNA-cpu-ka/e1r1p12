/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saait-si <saait-si@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 10:05:36 by saait-si          #+#    #+#             */
/*   Updated: 2023/12/08 16:43:25 by saait-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*destt;
	char	*ssrc;

	destt = (char *)dst;
	ssrc = (char *)src;
	if (src == dst)
		return (dst);
	i = 0;
	while (i < n)
	{
		destt[i] = ssrc[i];
		i++;
	}
	return (dst);
}
