/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saait-si <saait-si@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:17:31 by saait-si          #+#    #+#             */
/*   Updated: 2023/12/09 14:35:22 by saait-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*hp;

	if (!lst)
		return ;
	hp = *lst;
	if (*lst)
	{
		while (hp->next)
			hp = hp->next;
		hp->next = new;
	}
	else
		*lst = new;
}
