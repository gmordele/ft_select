/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 23:18:35 by gmordele          #+#    #+#             */
/*   Updated: 2017/05/26 02:02:36 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <termios.h>

# define KEY_UP 		0
# define KEY_DOWN 		1
# define KEY_RIGHT 		2
# define KEY_LEFT 		3
# define KEY_RETURN 	4
# define KEY_SPACE 		5
# define KEY_ESC 		6
# define KEY_DEL 		7
# define KEY_BACKSPACE	8

void			init_termios(void);
void			err_exit(char *error);
void			restore_term(void);
void			init_termcap(void);
int				pressed_key(int n, char *buf);
struct winsize	get_winsize(void);
int				tputc(int c);
void			print_word(char *word, int len, int row, int col);

#endif
