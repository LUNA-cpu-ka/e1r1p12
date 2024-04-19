/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saait-si <saait-si@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 23:16:06 by saait-si          #+#    #+#             */
/*   Updated: 2024/04/20 00:23:23 by saait-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//⚠️⚠️ You need libft ⚠️⚠️

void	validation_extantion(try *app, int ac, char **av)
{
	char	*ptr;

	if (ac < 2)
		error("Please enter the file name 🙂\n");
	ptr = strrchr(av[1], '.');
	if (!ptr || strncmp (ptr, ".ber", 4))
		error ("no extantion");
	app->file_name = av[1];
}

void	validation_exist(try *app)
{
	app->fd = open (app->file_name, O_RDONLY);
	if (app->fd == -1)
		error ("Not created");
}

char	**read_map(try *app)
{
	char	*temp;
	char	*line;
	char	*map;

	app->fd = open(app->file_name, O_RDONLY);
	map = malloc(sizeof(char));
	map[0] = '\0';
	line = get_next_line(app->fd);
	while (line)
	{
		temp = map;
		map = ft_strjoin (map, line);
		free (temp);
		free (line);
		line = get_next_line (app->fd);
	}
	app->dbl_ptr = ft_split(map, '\n');
	if (app->dbl_ptr == NULL)
		return (NULL);
	free (map);
	return (app->dbl_ptr);
}

int	height(try *app)
{
	app->h = 0;
	while (app->dbl_ptr[app->h])
		app->h++;
	return (app->h);
}

int	width(try *app)
{
	int	idx;

	idx = 0;
	app->w = ft_strlen(app->dbl_ptr[0]);
	while (app->dbl_ptr[idx])
	{
		if ((int)ft_strlen(app->dbl_ptr[idx]) != app->w)
			error ("hggh");
		idx++;
	}
	return (app->w);
}

int	ft_iselement(char elem)
{
	if (elem != 'E' && elem != 'P' && elem != 'C' && elem != '0' && elem != '1')
		return (0);
	return (1);
}

char	**map_copy_function(try *app)
{
	int	index;
	char	**map_copy;

	index = 0;
	map_copy = malloc(sizeof(char *) * (app->h + 1));
	if (!map_copy)
		return (NULL);
	while (app->dbl_ptr[index])
	{
		map_copy[index] = ft_strdup (app->dbl_ptr[index]);
		index++;
	}
	map_copy[index] = NULL;
	return (map_copy);
}

void	P_position(char **map, int *array)
{
	int	i;
	int	j;

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

void	flood_fill (char **map, int i, int j)
{
	if (map[i][j] == '1' || map[i][j] == 'A')
		return ;
	map[i][j] = 'A';
	flood_fill (map, i - 1, j);
	flood_fill (map, i + 1, j);
	flood_fill (map, i, j - 1);
	flood_fill (map, i, j + 1);
}

void	chack_flood_fill(char **copy_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (copy_map[i])
	{
		j = 0;
		while (copy_map[i][j])
		{
			if (copy_map[i][j] == 'C' || copy_map[i][j] == 'E')
				error ("am happy");
			j++;
		}
		i++;
	}
}

void	checking_path(try *app)
{
	char	**copy_map;
	int	array[2];
	int	i;

	i = 0;
	copy_map = map_copy_function(app);
	P_position(copy_map, array);
	flood_fill(copy_map, array[0], array[1]);
	while (copy_map[i])
	{
		// printf("%s\n", copy_map[i]);
		i++;
	}
	chack_flood_fill (copy_map);
	free (copy_map);
	return ;
}

int main(int ac, char** av)
{
    try app;
    validation_extantion(&app, ac, av);
    validation_exist(&app);
    app.dbl_ptr = read_map(&app);
	printf("the height is :%d\n\n", height(&app));
	int i = 0;
	int j = 0;
	while (app.dbl_ptr[i])
	{
		printf("%d: %s\n", i, app.dbl_ptr[i]);
		i++;
	}
	j = 0;
	//this is check the first and the last line (row)
	// printf("this is the how many app->w you have:%d",width(&app));	
	while((app.dbl_ptr[0][j] != '\0' || app.dbl_ptr[app.h - 1][j] != '\0'))
	{
		if(app.dbl_ptr[0][j] != '1' || app.dbl_ptr[app.h -1][j] != '1')
			error("You need '1' for the border\n");
		j++;
	}
	i = 0;
	// this is check the first and the last character (column)
	width(&app);
	while (app.dbl_ptr[i])
	{
		if(app.dbl_ptr[i][0] != '1' || app.dbl_ptr[i][app.w - 1] != '1')
		{
			printf("%c %c\n", app.dbl_ptr[i][0], app.dbl_ptr[i][app.w - 1]);
			printf("%d\n", app.w - 1);
			error("you need 1 for the border (column)\n");
		}
		i++;
	}
	//Checking the E P C 0 1 
	i = 0;
	while(app.dbl_ptr[i])
	{
		j = 0;
		while (app.dbl_ptr[i][j])
		{
			if(ft_iselement(app.dbl_ptr[i][j]) == 0)
				error("You need a charkajek\n");
			j++;
		}
		i++;
	}
	//chekcing how many chara we have
	int P = 0;
	int C = 0;
	int E = 0;
	i = 0;
	
	while (app.dbl_ptr[i])
	{
		j = 0;
		while (app.dbl_ptr[i][j])
		{
			if(app.dbl_ptr[i][j] == 'P')
				P++;
			if(app.dbl_ptr[i][j] == 'C')
				C++;
			if(app.dbl_ptr[i][j] == 'E')
				E++;
			j++;	
		}
		i++;
	}
	if(P > 1 || C == 0 || E > 1)
		error("Chack your characters!\n");
	
	checking_path(&app);












    // validation_map(&app,ac,av);

    // mlx_function();
    return(0);
}
