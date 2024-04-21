/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimention_counter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saait-si <saait-si@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:16:51 by saait-si          #+#    #+#             */
/*   Updated: 2024/04/21 04:28:01 by saait-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int map_height(try *app)
{
    app->h = 0;
    while (app->dbl_ptr[app->h])
        app->h++;
    if (!app->h)
        error ("Your file is empty 🤡");
    return (app->h);
}
int	len_to_new_line(char *str)
{
	int i;
	
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		i++;
	}
	return(i);
}
void map_width(try *app)
{
	app->w = len_to_new_line(app->dbl_ptr[0]);
	int i = 0;
	while (app->dbl_ptr[i])
	{
		if(app->w != len_to_new_line(app->dbl_ptr[i]))
			error ("Width error\n");
		i++;
	}
	app->w = len_to_new_line(app->dbl_ptr[0]);
}
