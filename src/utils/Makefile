# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msarigul <msarigul@student.42kocaeli.com.  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 10:09:01 by msarigul          #+#    #+#              #
#    Updated: 2022/12/27 12:19:44 by msarigul         ###   ########.tr        #
#                                                                              #
# **************************************************************************** #

OBJDIR	:= ../../obj
CFLAGS	:= -I ../../inc -c
FILES	:= draw.c\
				 draw_utils.c\
				 drawline.c\
				 ft_get_nextline.c\
				 ft_initfdf.c\
				 ft_parser.c\
				 parser_utils.c\


OBJ		:= $(FILES:%.c=$(OBJDIR)/%.o)

all: $(OBJ)

$(OBJDIR)/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all 
