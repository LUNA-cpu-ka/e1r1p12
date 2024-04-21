#ifndef SO_LONG_H
#define SO_LONG_H

#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <mlx.h>
#include "./libft/libft.h"
#include "./gnl/get_next_line.h"

typedef struct s_try
{
	char *file_name;
	char **dbl_ptr;
	void	*mlx;
	void	*win;
	void	*wall;
	void 	*ground;
	void 	*halwa;
	void	*player;
	void	*exit;
	int num_of_moves;
	int c_number;
	int di;
	int dj;
	int fd;
	int h;
	int w;
	int i;
	int P;
	int C;
	int E;
	int j;
} try;

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

void error(char *msg);
void validation_extantion(try *app, int ac, char **av);
void validation_exist(try *app);
int ft_contmapline(try *app);
char **read_map(try *app);
int map_height(try *app);
void map_width(try *app);
void    draw_map(try *app);

#endif