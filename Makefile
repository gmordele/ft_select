#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/17 00:00:01 by gmordele          #+#    #+#              #
#    Updated: 2017/06/05 18:54:09 by gmordele         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	ft_select

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

SRC			=	main.c					init_termios.c				err_exit.c			\
				restore_term.c			init_termcap.c				pressed_key.c		\
				get_winsize.c			tputc.c						print_word.c		\
				print_word_cur.c		make_arg_lst.c				remove_arg_lst.c	\
				sta_info.c				print_scr.c					get_arg.c			\
				red_screen.c			handle_key.c				get_n_args.c		\
				handle_page.c			handle_arrow.c				move_cur.c			\
				cur_move_right.c		cur_move_left.c				cur_move_up.c		\
				cur_move_down.c			same_page.c					handle_space.c		\
				print_foot.c			handle_del.c				remove_last.c		\
				switch_search_mode.c	handle_search_char.c

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
