/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saait-si <saait-si@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:24:01 by saait-si          #+#    #+#             */
/*   Updated: 2023/12/09 14:09:19 by saait-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words_num(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			j++;
		}
		else
			i++;
	}
	return (j);
}

static char	*string(const char *s, char c)
{
	char	*mini_s;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	mini_s = malloc(sizeof(char) * (len + 1));
	if (mini_s == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		mini_s[j] = s[i];
		j++;
		i++;
	}
	mini_s[j] = '\0';
	return (mini_s);
}

static void	ft_free(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
}

char	**ft_split(const char *s, char c)
{
	char	**array;
	int		i;
	int		twords;

	i = 0;
	if (s == NULL)
		return (NULL);
	array = malloc(sizeof(char *) * (words_num(s, c) + 1));
	if (array == NULL)
		return (NULL);
	twords = words_num(s, c);
	while (s && i < twords)
	{
		while (c == *s)
			s++;
		if (*s != c && *s)
			array[i] = string(s, c);
		if (array[i] == NULL)
			return (ft_free(array), free(array), NULL);
		while (*s != c && *s)
			s++;
		i++;
	}
	array[i] = NULL;
	return (array);
}
