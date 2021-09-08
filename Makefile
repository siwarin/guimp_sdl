# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cduverge <cduverge@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/23 17:18:33 by cduverge          #+#    #+#              #
#    Updated: 2021/09/08 16:00:11 by siwarin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : clean re fclean all

NAME = guimp

SRC = srcs/main.c srcs/graphics.c srcs/pixel.c srcs/mid-point_circle.c	

OBJ = $(SRC:.c=.o)

HEADERS = ./guimp.h

LIB = libft

INCL = include/

CC = gcc

VERT = \033[32m
CYAN = \033[36m
JAUNE = \033[33m
ROUGE = \033[31m
BLANC = \033[37m

OKJAUNE = $(CYAN) ====> $(JAUNE)[OK]$(BLANC)
KOROUGE = $(CYAN) ====> $(ROUGE)[KO]$(BLANC)

%.o: %.c
	@$(CC) -c -I libft/ $< -o $@ -I./

$(NAME): $(OBJ) $(SRC) | lib_rule
	@$(CC) -I libft/  $(OBJ) -I $(HEADERS) libft/libft.a -o $(NAME) $(shell pkg-config --cflags --libs sdl2 SDL2_ttf SDL2_image) -lm && echo "- $(VERT)Objects Creation$(OKJAUNE)" || (echo "- $(VERT)Objects Creation$(KOROUGE)" && false)

lib_rule:
	@$(MAKE) -C $(LIB) 1>/dev/null

all: $(NAME)

clean:
	@rm -rf $(OBJ)
	@echo "- $(VERT)Deleted objects$(OKJAUNE)"
	@$(MAKE) clean -C $(LIB)

fclean: clean
	@rm -rf $(NAME)
	@echo "- $(VERT)Deleted exe$(OKJAUNE)"
	@$(MAKE) fclean -C $(LIB)

re: fclean all
