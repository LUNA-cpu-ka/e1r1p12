#ifndef SO_LONG_H
# define SO_LONG_H

#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <mlx.h>
#include "./libft/libft.h"
#include "./gnl/get_next_line.h"


typedef struct try
{
    char *file_name;
	char **dbl_ptr;
    int fd;
	int h;
	int w;
}
try;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void error(char* msg);
void validation_extantion(try *app, int ac, char **av);
void validation_exist(try *app);
void    mlx_function();
void    my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif