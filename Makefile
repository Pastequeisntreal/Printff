# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gberthol <gberthol@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 16:57:34 by gberthol          #+#    #+#              #
#    Updated: 2023/11/13 11:46:50 by gberthol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =    libftprintf.a

CFLAGS    =	-Wall -Wextra -Werror -Ilibft -Iincludes
 
SRC	=	src/ft_printf.c			\
		libft/ft_putchar_fd.c	\
        libft/ft_putendl_fd.c	\
        libft/ft_puthexa.c		\
        libft/ft_putnbr_fd.c	\
        libft/ft_putstr_fd.c	\
        libft/ft_putunbr_fd.c

HEAD	=	libft.h	ft_printf.h

OBJ	=	$(SRC:.c=.o)

all:   $(NAME)

$(NAME):	$(OBJ) Makefile
	ar -rc $(NAME) $(OBJ)

%.o:%.c	$(HEAD)
	cc $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) libftprintf.a

re:		fclean
	$(MAKE)

.PHONY: all clean fclean re
