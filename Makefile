# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/22 13:48:19 by ltomasze          #+#    #+#              #
#    Updated: 2025/03/16 17:04:26 by mbany            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
SOURCES = src/get_next_line.c \
src/main.c \
src/key.c \
src/map.c \
src/free.c \
src/window.c \
src/check_tcm.c \
src/raycasting.c \
src/textures.c \
src/init_game.c\


OBJECTS = $(SOURCES:%.c=%.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -g
LIBFT = libft/libft.a
MINILIBX = minilibx-linux/libmlx_Linux.a

all: $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(MINILIBX):
	$(MAKE) -C minilibx-linux

$(NAME): $(OBJECTS) $(MINILIBX) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MINILIBX) -o $(NAME) -lXext -lX11 -lm -lz -D LINUX -no-pie

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	$(MAKE) -C libft clean
	$(MAKE) -C minilibx-linux clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean
	$(MAKE) -C minilibx-linux clean

re: fclean all

full: all clean

.PHONY: all clean fclean re full