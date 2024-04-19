/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saait-si <saait-si@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 08:52:37 by saait-si          #+#    #+#             */
/*   Updated: 2023/12/08 16:35:28 by saait-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*sub;

	i = 0;
	if (!s)
		return (NULL);
	j = ft_strlen(s);
	while (i + start < j && i < len)
		i++;
	sub = malloc(i + 1);
	if (!sub)
		return (NULL);
	j = 0;
	while (i > 0)
	{
		sub[j++] = s[start++];
		i--;
	}
	sub[j] = '\0';
	return (sub);
}
