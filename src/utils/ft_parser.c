#include "../../inc/fdf.h"

void ft_check_words_amount(t_parse *temps){
    if (temps -> is_first_elem){
        temps -> prev_words_amount = temps -> words_amount;
        temps -> is_first_elem = 0;
    }
}

static void ft_get_mapsize(t_fdf *fdf, t_parse *temps){
    fdf -> map_height = 0;
    temps -> is_first_elem = 1;
    temps -> line = ft_get_nextline(fdf -> fd);
    while (temps -> line){
        fdf -> map_height++;
        temps -> temp_str = temps -> line;
        temps -> line = ft_strtrim(temps -> line, "\32\t\n");
        if (!temps -> line)
            ft_error("Error: (wrong trim str)");
        temps -> words_amount = ft_item_counter(temps -> nums);
        ft_check_words_amount(temps);
        free(temps -> line);
        free(temps -> temp_str);
        ft_free_arr((void **)temps -> nums);
        temps -> line = ft_get_nextline(fdf -> fd);
        temps -> prev_words_amount = temps -> words_amount;
    }
    free(temps -> line);
    fdf -> map_width = temps -> words_amount;
}

void ft_parser(t_fdf *fdf, t_parse *temps, char *path){
    ft_open_map(fdf, path);
    ft_get_mapsize(fdf, temps);
}
