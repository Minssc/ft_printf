# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minsunki <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/28 22:26:03 by minsunki          #+#    #+#              #
#    Updated: 2021/03/28 22:32:54 by minsunki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
LIBFT		=	libft
LIBFT_NAME	=	libft.a
SRCS		=	ft_printf.c 

GCC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
OBJS		=	$(SRCS:.c=.o)
LIB			=	ar rcs
RM			=	rm -f

.c.o		:
			$(GCC) $(CFLAS) -c $< -o $(<:.c=.o)

$(NAME)		:	$(OBJS)
			make all -C $(LIBFT)/
			mv $(LIBFT)/$(LIBFT_NAME) $(NAME)
			$(LIB) $(NAME) $(OBJS)

all			:	$(NAME)

clean		:
			$(RM) $(OBJS)
			make clean -C $(LIBFT)

fclean		:	clean
			$(RM) $(NAME)
			make fclean -C $(LIBFT)

re:			:	fclean all

.PHONY		:	.c.o all clean fclean re
