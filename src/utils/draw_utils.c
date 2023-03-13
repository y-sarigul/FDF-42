#include "../../inc/fdf.h"

float ft_get_maxmod(float num1, float num2){
    if (num1 < 0)
        num1 *= -1;
    if (num2 < 0)
        num2 *= -1;
    if (num1 > num2)
        return (num1);
    else
        return (num2);
}

float ft_degtorad(int deg){
    return (deg * M_PI / 180);
}

int ft_get_zoom(int map_width, int map_height){
    if (map_height < 30 && map_width < 30)
        return (30);
    else if (map_height < 51 && map_width < 51)
        return (10);
    else if (map_height < 101 && map_width < 101)
        return (6);
    else if (map_height < 500 && map_width < 500)
        return (4);
    else
        return (2);
}
