#include "../../inc/fdf.h"

void ft_mlx_pixel_put(t_img *img, int x, int y, int color){
    char *dst;

    if (x < WIN_WIDTH && x > 0 && y < WIN_HEIGHT && y > 0){
        dst = img -> addr + (y * img -> line_length + x
            *(img -> bits_per_pixel / 8));
     *(unsigned int *)dst = color;
    }
}

void ft_clear_map(t_fdf *fdf){
    fdf -> temp_y = 0;
    while (fdf -> temp_y < WIN_HEIGHT){
        fdf -> temp_x = 0;
        while (fdf -> temp_x < WIN_WIDTH){
            ft_mlx_pixel_put(fdf -> img, fdf -> temp_x, fdf -> temp_y,
                             GREY);
            fdf -> temp_x++;
        }
        fdf -> temp_y++;
    }
    mlx_put_image_to_window(fdf -> mlx, fdf -> mlx_win
                            , fdf -> img -> img, 0, 0);
}

void ft_draw_map(t_fdf *fdf){
    fdf -> temp_y = -1;
    while (++fdf -> temp_y < fdf -> map_height){
        fdf -> temp_x = -1;
        while (++fdf -> temp_x < fdf -> map_width){
            if (fdf -> temp_x < fdf -> map_width - 1){
                fdf -> x1 = fdf -> temp_x;
                fdf -> y1 = fdf -> temp_y;
                fdf -> x2 = fdf -> temp_x + 1;
                fdf -> y2 = fdf -> temp_y;
                ft_draw_line(fdf, fdf -> img);
            }
            if (fdf -> temp_y < fdf -> map_height - 1){
                fdf -> x1 = fdf -> temp_x;
                fdf -> y1 = fdf -> temp_y;
                fdf -> x2 = fdf -> temp_x + 1;
                fdf -> y2 = fdf -> temp_y;
            }
        }
    }
}
