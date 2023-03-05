#include "../inc/fdf.h"

int main (int argc, char *argv[])
{
  t_fdf fdf;
  t_img img;
  t_parse temps;

  if (argc != 2)
    ft_error("Error: wrong amount of arguments");
  ft_parser(&fdf, &temps, argv[1]);
  
  return 0;
}
