# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 10:53:51 by tmouche           #+#    #+#              #
#    Updated: 2024/02/22 16:54:44 by tmouche          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HDRS := map.h structure.h texture.h window.h

SRCS := srcs/chained_list_utils1.c  srcs/map_creator_utils.c    srcs/texture_loc.c \
        srcs/chained_list_utils2.c  srcs/map_fixer.c            srcs/texture_print.c \
        srcs/free.c                 srcs/texture_sprite.c \
    	srcs/texture_utils.c \
        srcs/main.c                 srcs/window.c \
        srcs/map_all_utils.c        srcs/window_utils.c \
        srcs/map_checker.c          
        srcs/map_creator.c          

SRCS_D := srcs/
HDRS_D := headers/
OBJS_D := objs/

CFLAGS := -Wall -Wextra -Werror -g
CC := gcc
AR := ar rcs
RM := rm -rf

NAME := so_long

.PHONY: all clean fclean re libft mlx ft_printf

all: $(NAME)

$(NAME): $(OBJS_D) $(SRCS) $(HDRS) | libft mlx ft_printf
    $(CC) $(CFLAGS) $(SRCS) -I$(HDRS_D)libft -Llibft -lft -I$(HDRS_D)mlx_linux -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

$(OBJS_D):
    @mkdir -p $(OBJS_D)

libft:
    make -C libft

mlx:
    make -C mlx_linux

ft_printf:
    make -C ft_printf

$(OBJS_D)%.o: $(SRCS_D)%.c $(HDRS)
    $(CC) $(CFLAGS) -I$(HDRS_D)libft -I/usr/include -I$(HDRS_D)mlx_linux -c $< -o $@

clean:
    $(RM) -r $(OBJS_D)

fclean: clean
    $(RM) $(NAME)

re: fclean all

