/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saait-si <saait-si@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 23:16:06 by saait-si          #+#    #+#             */
/*   Updated: 2024/04/21 04:30:04 by saait-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// ⚠️⚠️ You need libft ⚠️⚠️

int ft_iselement(char elem)
{
	if (elem != 'E' && elem != 'P' && elem != 'C' && elem != '0' && elem != '1')
		return (0);
	return (1);
}

char **map_copy_function(try *app)
{
	int index;
	char **map_copy;

	index = 0;
	map_copy = malloc(sizeof(char *) * (app->h + 1));
	if (!map_copy)
		return (NULL);
	while (app->dbl_ptr[index])
	{
		map_copy[index] = ft_strdup(app->dbl_ptr[index]);
		index++;
	}
	map_copy[index] = NULL;
	return (map_copy);
}

void P_position(char **map, int *array)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				array[0] = i;
				array[1] = j;
			}
			j++;
		}
		i++;
	}
}

void flood_fill(char **map, int i, int j)
{
	if (map[i][j] == '1' || map[i][j] == 'A')
		return;
	if (map[i][j] == 'E')
	{
		map[i][j] = 'A';
		return ;
	}
	map[i][j] = 'A';
	flood_fill(map, i - 1, j);
	flood_fill(map, i + 1, j);
	flood_fill(map, i, j - 1);
	flood_fill(map, i, j + 1);
}

void chack_flood_fill(char **copy_map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (copy_map[i])
	{
		j = 0;
		while (copy_map[i][j])
		{
			if (copy_map[i][j] == 'C' || copy_map[i][j] == 'E')
				error("am happy");
			j++;
		}
		i++;
	}
}

void checking_path(try *app)
{
	char **copy_map;
	int array[2];
	int i;

	i = 0;
	copy_map = map_copy_function(app);
	P_position(copy_map, array);
	flood_fill(copy_map, array[0], array[1]);
	while (copy_map[i])
	{
		// printf("%s\n", copy_map[i]);
		i++;
	}
	chack_flood_fill(copy_map);
	free(copy_map);
	return;
}

char **ft_newline(try *app)
{
	int i;

	i = 0;
	while (app->dbl_ptr[i])
	{
		app->dbl_ptr[i] = ft_strtrim(app->dbl_ptr[i], "\n");
		i++;
	}
	return (app->dbl_ptr);
}

void ft_next(try *app)
{
	int j;
	int i;

	j = 0;
	app->dbl_ptr = ft_newline(app);
	while ((app->dbl_ptr[0][j] != '\0' || app->dbl_ptr[app->h - 1][j] != '\0'))
	{
		if (app->dbl_ptr[0][j] != '1' || app->dbl_ptr[app->h - 1][j] != '1')
			error("You need '1' for the border\n");
		j++;
	}
	i = 0;
	map_width(app);
	while (app->dbl_ptr[i])
	{
		if (app->dbl_ptr[i][0] != '1' || app->dbl_ptr[i][app->w - 1] != '1')
		{
			printf("%c %c\n", app->dbl_ptr[i][0], app->dbl_ptr[i][app->w - 1]);
			printf("%d\n", app->w - 1);
			error("you need 1 for the border (column)\n");
		}
		i++;
	}
}
void ft_checking(try app)
{
	int i;
	int j;

	i = 0;
	while (app.dbl_ptr[i])
	{
		j = 0;
		while (app.dbl_ptr[i][j])
		{
			if (ft_iselement(app.dbl_ptr[i][j]) == 0)
				error("You need a charkajek\n");
			j++;
		}
		i++;
	}
	return;
}
void ft_chrcking_how_many_charteres(try *app)
{
	app->i = 0;
	app->P = 0;
	app->E = 0;
	app->j = 0;
	while (app->dbl_ptr[app->i])
	{
		app->j = 0;
		while (app->dbl_ptr[app->i][app->j])
		{
			if (app->dbl_ptr[app->i][app->j] == 'P')
				app->P++;
			if (app->dbl_ptr[app->i][app->j] == 'C')
				app->c_number++;
			if (app->dbl_ptr[app->i][app->j] == 'E')
				app->E++;
			app->j++;
		}
		app->i++;
	}
	if (app->P > 1 || app->c_number == 0 || app->E > 1)
		error("Chack your characters!\n");
}

void	load_images(try *app)
{
	int	width;
	int	height;

	app->ground = mlx_xpm_file_to_image(app->mlx, "img/groundjwd.xpm", &width, &height);
	if (app->ground == NULL)
		error("1can't load images\n");
	app->player = mlx_xpm_file_to_image(app->mlx, "img/left2jawad.xpm", &width, &height);
	if (app->player == NULL)
		error("2can't load images\n");
	app->halwa = mlx_xpm_file_to_image(app->mlx, "img/strawberryjawad.xpm", &width, &height);
	if (app->halwa == NULL)
		error("3can't load images\n");
	app->exit = mlx_xpm_file_to_image(app->mlx, "img/exit_close.xpm", &width, &height);
	if (app->exit == NULL)
		error("4can't load images\n");
	app->wall = mlx_xpm_file_to_image(app->mlx, "img/walljawad.xpm", &width, &height);
	if (app->wall == NULL)
		error("5can't load images\n");
}
void change_player_position(try *app)
{
	int array[2];
	
	P_position(app->dbl_ptr, array);
	if (app->dbl_ptr[array[0] + app->di][array[1] + app->dj] == '1')	
		return ;
	if (app->dbl_ptr[array[0] + app->di][array[1] + app->dj] == 'C')
		app->c_number--;
	if (app->dbl_ptr[array[0] + app->di][array[1] + app->dj] == 'E' && app->c_number == 0)
	{
		write(1,"You WOOON!\n", 11);
		exit(0);
	}
	if (app->dbl_ptr[array[0] + app->di][array[1] + app->dj] == 'E' && app->c_number != 0)
		return;
	app->dbl_ptr[array[0]][array[1]] = '0';
	app->dbl_ptr[array[0] + app->di][array[1] + app->dj] = 'P';
	if (app->di != 0 || app->dj != 0)
	{
		app->num_of_moves++;
		ft_putnbr_fd(app->num_of_moves, 1);
		write(1,"\n",1);
	}
	// int i = 0;
	// while (app->dbl_ptr[i])
	// 	printf("\"%s\"\n", app->dbl_ptr[i++]);
}

int	handle_keys(int keycode, try *app)
{
	(void)app;
	app->di = 0;
	app->dj = 0;
	// printf("keycode: %d\n", keycode);
	if (keycode == 53)
		exit(0);
	if (keycode == 125)
		app->di = 1;
	if (keycode == 126)
		app->di = -1;
	if (keycode == 124)
		app->dj = 1;
	if (keycode == 123)
		app->dj = -1;
	change_player_position(app);
	draw_map(app);
	return (0);
}

int	exit_game(try *app)
{
	(void)app;
	exit(0);
}

int main(int ac, char **av)
{
	try app;
	
	app.mlx = mlx_init();
	validation_extantion(&app, ac, av);
	validation_exist(&app);
	app.dbl_ptr = read_map(&app);
	map_width(&app);
	app.num_of_moves = 0;
	app.win = mlx_new_window(app.mlx, app.w * 30, map_height(&app) * 30, "so_long");
	printf("the height is :%d\n", map_height(&app));
	printf("the width: %d\n", app.w);
	ft_next(&app);
	ft_checking(app);
	ft_chrcking_how_many_charteres(&app);
	checking_path(&app);
	// validation_map(&app,ac,av);
	load_images(&app);
	draw_map(&app);
	mlx_hook(app.win, 17, 0, exit_game, &app);
	mlx_hook(app.win, 2, 1L>>0, handle_keys, &app);
	mlx_loop(app.mlx);
	return (0);
}
