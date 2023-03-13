#include "../inc/fdf.h"
#include <stdio.h>

int main (int argc, char *argv[])
{
    t_fdf   fdf;
    t_img   img;
    t_parse temps;

    if (argc != 2)
        ft_error("Error: wrong arguments");
    ft_parser(&fdf, &temps, argv[1]);
    ft_initfdf(&fdf);
    fdf.img = &img;
    fdf.mlx = mlx_init();
    fdf.mlx_win = mlx_new_window(fdf.mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
    img.img = mlx_new_image(fdf.mlx, WIN_WIDTH, WIN_HEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    ft_clear_map(&fdf);
    ft_draw_map(&fdf);
}
