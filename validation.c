/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saait-si <saait-si@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 10:10:35 by saait-si          #+#    #+#             */
/*   Updated: 2024/04/20 10:11:16 by saait-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void validation_extantion(try *app, int ac, char **av)
{
	char *ptr;

	if (ac < 2)
		error("Please enter the file name 🙂\n");
	ptr = ft_strrchr(av[1], '.');
	if (!ptr || ft_strncmp(ptr, ".ber", ft_strlen(ptr)))
		error("no extantion");
	app->file_name = av[1];
}
void validation_exist(try *app)
{
	app->fd = open(app->file_name, O_RDONLY);
	if (app->fd == -1)
		error("Not created");
}