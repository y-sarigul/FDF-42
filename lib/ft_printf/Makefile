# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msarigul <msarigul@student.42kocaeli.com.  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 10:09:01 by msarigul          #+#    #+#              #
#    Updated: 2022/08/02 10:09:06 by msarigul         ###   ########.tr        #
#                                                                              #
# **************************************************************************** #

OBJDIR	:= ../../obj
CFLAGS	:= -Wall -Wextra -Werror -I ../../inc -c
FILES	:= ft_print_pointer.c \
	   ft_printf.c \
	   ft_printf_hex.c\
	   ft_printf_number.c\
	   ft_printf_utils.c\

OBJ		:= $(FILES:%.c=$(OBJDIR)/%.o)

all: $(OBJ)

$(OBJDIR)/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re
