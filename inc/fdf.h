#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720 
/*COLORS*/
# define WHITE 0xFFFFFF
# define GREY 0x101010

typedef struct s_img
{
  void *img;
  char *addr;
  int bits_per_pixel;
  int line_length;
  int endian;
} t_img;

typedef struct s_fdf
{
  t_img *img;
  int fd;
  int map_width;
  int map_height;
  int trans_x;
  int trans_y;
  int color;
  int temp_y;
  int temp_x;
  int **alts;
  float x1;
  float y1;
  float x2;
  float y2;
  float z1;
  float z2;
  float alt_zoom;
  float angle_x;
  float angle_y;
  float angle_z;
  float zoom;
  void *mlx;
  void *mlx_win;
} t_fdf;

typedef struct s_parse
{
  char *line;
  char **nums;
  int is_first_elem;
  char *temp_str;
  int words_amount;
  int prev_words_amount;
} t_parse;

/*ft_initfdf.c*/
void ft_initfdf(t_fdf *fdf);

/*parser_utils.c*/
void ft_error(char *message);
void ft_open_map(t_fdf *fdf, char *path);
int ft_item_counter(char **arr);
void ft_free_arr(void **arr);

/*parser.c*/
void ft_parser(t_fdf *fdf, t_parse *temps, char *path);


/*ft_get_nextline.c*/
char *ft_get_nextline(int fd);

/*draw_utils.c*/
float ft_degtorad(int deg);
float ft_get_maxmod(float num1, float num2);
int ft_get_zoom(int map_width, int map_height);

/*draw.c*/
void ft_clear_map(t_fdf *fdf);
void ft_draw_map(t_fdf *fdf);
void ft_mlx_pixel_put(t_img *img, int x, int y, int color);

/*drawline*/
void ft_draw_line(t_fdf *fdf, t_img *img);


#endif
