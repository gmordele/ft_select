/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 23:18:35 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/02 17:08:59 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <termios.h>
# include <string.h>

# define KEY_UP 		0
# define KEY_DOWN 		1
# define KEY_RIGHT 		2
# define KEY_LEFT 		3
# define KEY_RETURN 	4
# define KEY_SPACE 		5
# define KEY_ESC 		6
# define KEY_DEL 		7
# define KEY_BACKSPACE	8
# define KEY_CTRL_S		9
# define KEY_PAGE_UP	10
# define KEY_PAGE_DOWN	11

# define SELECTED		100
# define UNSELECTED		101

# define STATE_NORMAL	200
# define STATE_SEARCH	201
# define STATE_BLOCK_NO	202
# define STATE_BLOCK_SE	203

typedef struct	s_arg_lst
{
	int					rank;
	char				*arg;
	int					state;
	struct s_arg_lst	*next;
	struct s_arg_lst	*prev;
}				t_arg_lst;

typedef struct	s_info
{
	int				exit;
	int				cur_pos;
	int				len;
	struct termios	saved_termios;
	int				is_saved;
	int				col;
	int				row;
	t_arg_lst		*arg_lst;
	int				state;
	int				words_row;
	int				words_col;
	int				words_page;
}				t_info;


void			init_termios(t_info *info);
void			err_exit(t_info *info, char *error);
void			restore_term(t_info *info);
void			init_termcap(t_info *info);
int				pressed_key(int n, char *buf);
void			get_winsize(t_info *info);
int				tputc(int c);
void			print_word_uns(char *word, int len, int row, int col);
void			print_word_sel(char *word, int len, int row, int col);
void			print_word_foot(char *word, int len, int row, int col);
void			print_word_cur_uns(char *word, int len, int row, int col);
void			print_word_cur_sel(char *word, int len, int row, int col);
void			make_arg_lst(t_info *info, int argc, char **argv);
void			remove_arg_lst(t_arg_lst **first, int rank);
t_info			*sta_info(t_info *info);
void			print_scr(t_info *info);
t_arg_lst		*get_arg(t_info *info, int rank);
void			red_screen(t_info *info);
void			handle_key(t_info *info, int key);

#endif
