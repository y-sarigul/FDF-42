#include "../../inc/fdf.h"

static void ft_isometric(t_fdf *fdf){
    fdf -> x1 = fdf -> x1 * cos (fdf -> angle_z) - fdf -> y1 * sin(fdf -> angle_z);
    fdf -> x2 = fdf -> x2 * cos (fdf -> angle_z) - fdf -> y2 * sin(fdf -> angle_z);
    fdf -> y1 = fdf -> x1 * cos (fdf -> angle_z) - fdf -> y1 * sin(fdf -> angle_z);
    fdf -> y2 = fdf -> x2 * cos (fdf -> angle_z) - fdf -> y2 * sin(fdf -> angle_z);
}

static void ft_rotate(t_fdf *fdf){
    fdf -> x1 = fdf -> x1 * cos(fdf -> angle_z) - fdf -> y1 * sin(fdf -> angle_z);
    fdf -> x2 = fdf -> x2 * cos(fdf -> angle_y) - fdf -> z2 * sin(fdf -> angle_y);
    fdf -> y1 = fdf -> y1 * cos(fdf -> angle_x) - fdf -> z1 * sin(fdf -> angle_x);
    fdf -> y2 = fdf -> y2 * cos(fdf -> angle_x) - fdf -> z2 * sin(fdf -> angle_x);

}

static void ft_transform_coords(t_fdf *fdf){
    fdf -> z1 = fdf -> alts[(int)fdf -> y1][(int)fdf -> x1] * fdf -> alt_zoom;
    fdf -> z2 = fdf -> alts[(int)fdf -> y2][(int)fdf -> x2] * fdf -> alt_zoom;
    fdf -> x1 = (fdf -> x1 - fdf -> map_width / 2) * fdf -> zoom;
    fdf -> x2 = (fdf -> x2 - fdf -> map_width / 2) * fdf -> zoom;
    fdf -> y1 = (fdf -> y1 - fdf -> map_height / 2) * fdf -> zoom;
    fdf -> y2 = (fdf -> y2 - fdf -> map_height / 2) * fdf -> zoom;
    ft_rotate(fdf);
    ft_isometric(fdf);
    fdf -> x1 += fdf -> trans_x;
    fdf -> x2 += fdf -> trans_x;
    fdf -> y1 += fdf -> trans_y;
    fdf -> y2 += fdf -> trans_y;
}

void ft_draw_line(t_fdf *fdf, t_img *img){
    float dx;
    float dy;
    float max;

    ft_transform_coords(fdf);
    dx = fdf -> x2 - fdf -> x1;
    dy = fdf -> y2 - fdf -> y1;
    max = ft_get_maxmod(dx, dy);
    dx /= max;
    dy /= max;
    while ((int)(fdf -> x2 - fdf -> x1) || (int)(fdf -> y2 - fdf -> y1)){
        ft_mlx_pixel_put(img, fdf -> x1, fdf -> y1, fdf -> color);
        fdf -> x1 += dx;
        fdf -> y1 += dy;
    }
}
