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

SRCS		:=	

HDRS		:=	structure.h map.h window.h texture.h

SRCS_D		:=	SRCS/

HDRS_D		:=	HDRS/

OBJS_D		:=	objs/

OBJS		:=	$(SRCS:%.c=$(OBJS_D)%.o)

CFLAGS		:=	-Wall -Wextra -Werror -g 

AR			:=	ar rcs

NAME		:=	so_long

all			:	$(NAME)

$(NAME)		:	$(OBJS_D) $(OBJS) libft Makefile mlx Makefile
				$(CC) $(OBJS) -Ilibft -Llibft -lft -Lmlx_linux -lmlx_Linux -Imlx_linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

$(OBJS)		:	$(OBJS_D)%.o: $(SRCS_D)%.c $(HDRS)
					$(CC) $(CFLAGS) -Ilibft -I/usr/include -Imlx_linux -c $< -o $@

$(OBJS_D)	:
				@mkdir -p $(OBJS_D)

libft		:
				make -C libft

mlx			:
				make -C mlx_linux

clean		:
				$(RM) -r $(OBJS) $(OBJS_D)

fclean		: clean
				$(RM) $(NAME)

re			: fclean all

.PHONY		: all clean fclean re
