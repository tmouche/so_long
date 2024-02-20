# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 10:53:51 by tmouche           #+#    #+#              #
#    Updated: 2024/02/20 13:16:45 by tmouche          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS        := map_checker_utils.c map_checker.c map_creator_utils.c map_creator.c map_dup.c map_ennemies.c colors_texture.c ft_window.c window_utils.c colors_tab.c movement_chara.c movement_checker.c movement_utils.c movement_event.c movement_projectile.c colors_struct.c ft_position.c main.c

HEAD		:= ft_map.h ft_error.h ft_window.h ft_movement.h ft_base.h ft_texture.h ft_structure.h

SRCS_D        :=    ./SRCS/

OBJS_D        :=    objs/

OBJS        :=    $(SRCS:%.c=$(OBJS_D)%.o)

CFLAGS        :=    -Wall -Wextra -g #-Werror

AR            :=    ar rcs

NAME        :=    so_long

all            :    $(NAME)

$(NAME)        :    $(OBJS_D) $(OBJS) libft Makefile mlx Makefile
					$(CC) $(OBJS) -Ilibft -Llibft -lft -Lmlx_linux -lmlx_Linux -Imlx_linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

$(OBJS)        :    $(OBJS_D)%.o: $(SRCS_D)%.c $(HEAD)
					$(CC) $(CFLAGS) -Ilibft -I/usr/include -Imlx_linux -c $< -o $@

$(OBJS_D)    :
				@mkdir -p $(OBJS_D)

libft			:
				make -C libft

mlx            :
				make -C mlx_linux

clean        :
				$(RM) -r $(OBJS) $(OBJS_D)

fclean        :    clean
				$(RM) $(NAME)

re            :    fclean all


.PHONY: all bonus clean fclean re
