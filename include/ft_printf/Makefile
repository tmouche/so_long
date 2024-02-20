# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 13:32:16 by tmouche           #+#    #+#              #
#    Updated: 2024/02/19 17:28:51 by tmouche          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_printf_utils.c

OBJS	:=	$(SRCS:.c=.o)

HEAD	:=	ft_printf.h

CFLAGS	:=	-Wall -Wextra -Werror

LFLAGS	:=	-fsanitize=leak,address

AR	:=	ar rcs

NAME	:= libftprintf.a

all		:	$(NAME)

%.o		:	%.c ${HEAD}
	${CC} ${CFLAGS} -c $< -o $@

$(NAME)	:	$(OBJS) Makefile 
			$(AR) $(NAME) $(OBJS)

clean	:
	rm -f $(OBJS)

fclean	:	clean
				rm -f $(NAME)

re	:	fclean all

.PHONY: all clean fclean re