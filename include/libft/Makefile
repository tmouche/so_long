# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmouche < tmouche@student.42lyon.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 13:32:16 by tmouche           #+#    #+#              #
#    Updated: 2024/02/23 19:46:14 by tmouche          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_toupper.c ft_tolower.c ft_atoi.c ft_strncmp.c ft_memcmp.c ft_calloc.c\
		ft_bzero.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strdup.c ft_memchr.c ft_strlen.c ft_strlcpy.c ft_strlcat.c\
		ft_strjoin.c ft_substr.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
		ft_abs.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c\

OBJS	:=	$(SRCS:.c=.o)

B_OBJS	:=	$(BONUS:.c=.o)

HEAD	:=	libft.h

CFLAGS	:=	-Wall -Wextra -Werror

LFLAGS	:=	#-fsanitize=leak,address

AR	:=	ar rcs

NAME	:=	libft.a

all		:	$(NAME)

%.o		:	%.c ${HEAD}
	${CC} ${CFLAGS} $(LFLAGS) -c $< -o $@

$(NAME)	:	$(OBJS) Makefile 
			$(AR) $(NAME) $(OBJS)

bonus	:
	@make SRCS="$(SRCS) $(BONUS)"

clean	:
	$(RM) -f $(OBJS) $(B_OBJS)

fclean	:	clean
				$(RM) $(NAME)

re	:	fclean all

.PHONY: all clean fclean re bonus
