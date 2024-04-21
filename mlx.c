
#include "so_long.h"

void    put_wall(try *app)
{
    int i;
    int j;

    i = 0;
    while(app->dbl_ptr[i])
    {
        j = 0;
        while (app->dbl_ptr[i][j])
        {
            if (app->dbl_ptr[i][j] == '1')
                mlx_put_image_to_window(app->mlx, app->win, app->wall, j * 30, i * 30);
            j++;
        }
        i++;
    }
}
void    put_halwa(try *app)
{
    int i = 0;
    int j;
    while (app->dbl_ptr[i])
    {
        j = 0;
        while (app->dbl_ptr[i][j])
        {
            if(app->dbl_ptr[i][j] == 'C')
                mlx_put_image_to_window(app->mlx, app->win,app->halwa, j * 30, i * 30);
            j++;
        }
        i++;
    }
    
}
void    put_player(try *app)
{
    int i = 0;
    int j;
    while (app->dbl_ptr[i])
    {
        j = 0;
        while (app->dbl_ptr[i][j])
        {
            if(app->dbl_ptr[i][j] == 'P')
                mlx_put_image_to_window(app->mlx, app->win,app->player, j * 30, i * 30);
            j++;
        }
        i++;
    }
    
}
void    put_exit(try *app)
{
    int i = 0;
    int j;
    while (app->dbl_ptr[i])
    {
        j = 0;
        while (app->dbl_ptr[i][j])
        {
            if(app->dbl_ptr[i][j] == 'E')
                mlx_put_image_to_window(app->mlx, app->win,app->exit, j * 30, i * 30);
            j++;
        }
        i++;
    }
}

void    draw_map(try *app)
{ 
    int i = 0;
    int j;
    while (app->dbl_ptr[i])
    {
        j = 0;
        while (app->dbl_ptr[i][j])
        {
            mlx_put_image_to_window(app->mlx, app->win, app->ground, j * 30, i * 30);
            if (app->dbl_ptr[i][j] == 'P')
                mlx_put_image_to_window(app->mlx, app->win, app->player, j * 30, i * 30);
            if (app->dbl_ptr[i][j] == 'E')
                mlx_put_image_to_window(app->mlx, app->win, app->exit, j * 30, i * 30);
            if (app->dbl_ptr[i][j] == 'C')
                mlx_put_image_to_window(app->mlx, app->win, app->halwa, j * 30, i * 30);
            if (app->dbl_ptr[i][j] == '1')
                mlx_put_image_to_window(app->mlx, app->win, app->wall, j * 30, i * 30);
            j++;
        }
        i++;
    }
}
