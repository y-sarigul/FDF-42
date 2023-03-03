# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msarigul <msarigul@student.42kocaeli.com.  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 10:02:09 by msarigul          #+#    #+#              #
#    Updated: 2022/12/28 11:22:39 by msarigul         ###   ########.tr        #
#                                                                              #
# **************************************************************************** #

NAME			:= fdf.a 

OBJDIR			:= obj
LIBFT			:= $(OBJDIR)/libft.a
FT_PRINTF		:= $(OBJDIR)/ft_printf.a
GET				:= $(OBJDIR)/get_next_line.a
MLX 			:= $(OBJDIR)/libmlx.a
UTILS 			:= $(OBJEDIR)/utils.a
CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror -I ./inc

$(NAME): $(OBJDIR) $(MLX) $(LIBFT) $(FT_PRINTF) $(GET) $(UTILS)
	@ar -rcs $(NAME) $(OBJDIR)/*.o 
	@gcc ./src/main.c fdf.a -framework OpenGL -framework AppKit -o fdf -I ./inc

$(OBJDIR):
	@echo "Creating objects file"
	@mkdir -p $(OBJDIR)

$(LIBFT):
	@echo "Libft creating"
	@make -C ./lib/libft

$(FT_PRINTF):
	@echo "Ft_printf creating"
	@make -C ./lib/ft_printf

$(GET):
	@echo "Get Next Line creating"
	@make -C ./lib/get_next_line/

$(UTILS):
	@echo "Utils creating"
	@make -C src/utils 

$(MLX):
	@make -C ./lib/mlx
	@mv ./lib/mlx/*.o ./obj


all: $(NAME)

clean:
	@rm -f $(OBJDIR)/*.o

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJDIR)
	@rm -rf ./lib/mlx/*.o
	@rm fdf

re: fclean all
m:
	@gcc ./src/main.c ./fdf.a -framework OpenGL -framework AppKit -o fdf -I ./inc/
	@./main ./test_maps/42.fdf
	@rm main

.PHONY: all re clean fclean m
