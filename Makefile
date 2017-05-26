#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/17 00:00:01 by gmordele          #+#    #+#              #
#    Updated: 2017/05/26 02:02:02 by gmordele         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	ft_select

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

SRC			=	main.c					init_termios.c				err_exit.c		\
				restore_term.c			init_termcap.c				pressed_key.c	\
				get_winsize.c			tputc.c						print_word.c

OBJ			=	$(SRC:%.c=%.o)

DEST_SRC	=	./src/

DEST_INC	=	./include/

HEADERS		=	$(DEST_INC) $(DEST_LIB)

DEST_LIB	=	./libft

LIBFT		=	$(DEST_LIB)/libft.a

all 		:	mklib $(NAME)

$(NAME)		:	$(LIBFT) $(OBJ) $(HEADERS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) -I$(DEST_INC) -I$(DEST_LIB) -ltermcap

%.o			:	$(DEST_SRC)%.c $(HEADERS) $(LIBFT)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(DEST_INC) -I$(DEST_LIB)

mklib		:
	make -C $(DEST_LIB) 

clean		:
	rm -f $(OBJ)
	make clean -C $(DEST_LIB)

fclean		:	clean
	rm -f $(NAME)
	make fclean -C $(DEST_LIB)

re			:	fclean all

.PHONY:all clean fclean re mklib
