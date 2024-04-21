/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saait-si <saait-si@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 10:13:47 by saait-si          #+#    #+#             */
/*   Updated: 2024/04/21 01:51:37 by saait-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//we want here to count how many liines do we have:
//it is so easy to do iit soo let's goooooo

int ft_contmapline(try *app)
{
    char    *line;
    app->i = 0;
    app->fd = open(app->file_name, O_RDONLY);
    
    line = get_next_line(app->fd);
    while (line)
    {
        app->i++;
        free(line);
        line = get_next_line(app->fd);
    }
    return(app->i);
}

char **read_map(try *app)
{
	char **temp;
	char *line;
	int i;

	app->h = ft_contmapline(app);
	app->fd = open(app->file_name, O_RDONLY);
	line = get_next_line(app->fd);
	i = 0;
	temp = malloc((app->h + 1) * sizeof(char *));
	if (!temp)
		return (NULL);
	while (line)
	{
		if (line[0] == '\n')
			error("map contains an empty line\n");
		temp[i] = ft_strdup(line);
		i++;
		free(line);
		line = get_next_line(app->fd);
	}
	temp[i] = NULL;
	int j = 0;
	while (temp[j])
	{
		printf("\"%s\"\n", temp[j]);
		j++;
	}
	return (temp);
}
