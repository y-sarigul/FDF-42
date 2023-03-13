#include "../../inc/fdf.h"

void ft_initfdf(t_fdf *fdf){
    fdf -> trans_x = WIN_WIDTH / 2;
    fdf -> trans_y = WIN_HEIGHT / 2;
    fdf -> alt_zoom = 2;
    fdf -> angle_x = ft_degtorad(25);
    fdf -> angle_y = ft_degtorad(-30);
    fdf -> angle_z = ft_degtorad(20);
    fdf -> zoom = ft_get_zoom(fdf -> map_width, fdf -> map_height);
    fdf -> color = WHITE;
}
