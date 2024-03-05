# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 10:53:51 by tmouche           #+#    #+#              #
#    Updated: 2024/03/05 16:29:18 by tmouche          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HDRS := map.h structure.h texture.h window.h movement.h

SRCS := chained_list_utils1.c map_creator_utils.c texture_loc.c \
        chained_list_utils2.c map_fixer.c texture_print.c \
        free.c texture_sprite.c \
        texture_utils.c \
        main.c window.c \
        map_all_utils.c window_utils.c \
        map_checker.c map_creator.c window_hooker.c \
		movement_checker_utils.c movement_checker.c movement_chara.c movement_event.c movement_utils.c\
		window_looper.c movement_projectile.c texture_animation.c free_texture.c movement_knife.c

SRCS_D := SRCS/
HDRS_D := HDRS/
OBJS_D := OBJS/
INC_D  := include/

CFLAGS := -Wall -Wextra -Werror -g
CC := cc
AR := ar rcs
RM := rm -rf

NAME := so_long	
OBJS := $(SRCS:%.c=$(OBJS_D)%.o)

all: libft ft_printf minilibx-linux $(NAME)

$(NAME): $(OBJS_D) $(OBJS) | libft ft_printf minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) -I$(INC_D)libft -L$(INC_D)libft -lft -I$(INC_D)minilibx-linux -L$(INC_D)minilibx-linux -lmlx -L$(INC_D)ft_printf -lftprintf -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)


$(OBJS_D)%.o: $(SRCS_D)%.c $(HDRS:%=$(HDRS_D)%)
	$(CC) $(CFLAGS) -I$(INC_D)libft -I$(INC_D)ft_printf -I$(INC_D)minilibx-linux -c $< -o $@

$(OBJS_D):
	@mkdir -p $(OBJS_D)

libft:
	$(MAKE) -C $(INC_D)libft

ft_printf:
	$(MAKE) -C $(INC_D)ft_printf

minilibx-linux:
	$(MAKE) -C $(INC_D)minilibx-linux

clean:
	$(RM) -r $(OBJS_D)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(INC_D)libft fclean
	$(MAKE) -C $(INC_D)ft_printf fclean
	$(MAKE) -C $(INC_D)minilibx-linux clean

re: fclean all

.PHONY: all clean fclean re libft ft_printf minilibx-linux
