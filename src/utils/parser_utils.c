#include "../../inc/fdf.h"

void ft_error(char *message)
{
  ft_putendl_fd(message, 2);
  exit(EXIT_FAILURE);
}

void ft_open_map(t_fdf *fdf, char *path)
{
  fdf -> fd = open(path, O_RDONLY);
  if (fdf -> fd == -1)
  {
    perror("Error (wrong open file)");
    exit(EXIT_FAILURE);
  }
}

int ft_item_counter(char **arr)
{
  int i;

  i = 0;
  while (arr[i])
    i++;
  return (i);
}

void ft_free_arr(void **arr){
  int i;

  i = 0;
  while (arr[i]){
    free(arr[i]);
    i++;
  }
  free(arr);
}
