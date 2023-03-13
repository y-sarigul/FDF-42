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
  float alt_zoom;
  float angle_x;
  float angle_y;
  float angle_z;
  float zoom;
  int color;
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
int ft_get_zoom(int map_width, int map_height);


#endif
