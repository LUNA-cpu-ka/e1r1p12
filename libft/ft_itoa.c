/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saait-si <saait-si@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:35:11 by alaktari          #+#    #+#             */
/*   Updated: 2023/12/07 13:20:28 by saait-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	digits_len(int n)
{
	size_t	the_len;

	the_len = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n == 2147483647)
		return (10);
	if (n < 0)
		the_len++;
	while (n != 0)
	{
		n = n / 10;
		the_len++;
	}
	return (the_len);
}

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	x;
	char	*fun_itoa;

	i = 0;
	x = digits_len(n);
	fun_itoa = malloc(sizeof(char) * (x + 1));
	if (!(fun_itoa))
		return (NULL);
	fun_itoa[x] = '\0';
	if (n < 0)
	{
		fun_itoa[0] = '-';
		i = 1;
	}
	while (x-- > i)
	{
		if (n < 0)
			fun_itoa[x] = '0' + (n % 10) * (-1);
		else
			fun_itoa[x] = '0' + (n % 10);
		n = n / 10;
	}
	return (fun_itoa);
}
