#include "../inc/fdf.h"

int main (int argc, char *argv[])
{
    t_fdf   fdf;
    t_img   img;
    t_parse temps;

    if (argc != 2)
        ft_error("Error: wrong arguments");
    ft_parser(&fdf, &temps, argv[1]);
    ft_initfdf(&fdf);
}
