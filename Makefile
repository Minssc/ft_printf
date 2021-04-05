# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minsunki <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/28 22:26:03 by minsunki          #+#    #+#              #
#    Updated: 2021/04/05 16:09:35 by minsunki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
LIBFT		=	libft
LIBFT_NAME	=	libft.a
SRCS		=	ft_printf.c \
				ft_print_char.c \
				ft_print_dec.c \
				ft_print_ptr.c \
				ft_print_str.c \
				ft_print_udec.c

GCC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
OBJS		=	$(SRCS:.c=.o)
INCS		=	.
LIB			=	ar rcs
RM			=	rm -f

.c.o		:
			$(GCC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

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

re			:	fclean all

.PHONY		:	.c.o all clean fclean re
