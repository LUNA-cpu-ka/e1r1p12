#include "so_long.h"

void    mlx_function()
{
    void    *mlx;
    void    *mlx_win;
    void    *img;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 800, 600, "🇲🇦 Dima maghreb 🇲🇦");
    // mlx_pixel_put(mlx, mlx_win, 640/2, 180/2, 0xF000FF);
    //image = mlx_new_image(mlx, 1920, 1080);
    // mlx_string_put(mlx, mlx_win, 400, 300, 0x2FB59F, "mariwana🇲🇦");
    img = mlx_new_image(mlx, 78, 300);

    // Your enchanted canvas is ready for artistic expression

    // Time to gracefully dispose of the image
    mlx_destroy_image(mlx, img);
    mlx_loop(mlx);
 
}