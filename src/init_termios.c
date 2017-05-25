/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_termios.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 00:15:31 by gmordele          #+#    #+#             */
/*   Updated: 2017/05/25 16:33:21 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <term.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_select.h"

struct termios	saved_termios;
int				is_saved = 0;

//void			ft_putc()

static void		save_termios(struct termios saved)
{
	saved_termios = saved;
	is_saved = 1;
}

void			init_termios(void)
{
	struct termios	buf;
	struct termios	saved;

	if (tcgetattr(STDIN_FILENO, &saved) < 0)
		err_exit("Error tcgetattr");
	save_termios(saved);
	buf = saved;
	buf.c_lflag &= ~(ECHO | ICANON);
	buf.c_cc[VMIN] = 1;
	buf.c_cc[VTIME] = 0;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &buf) < 0)
		err_exit("Error tcsetattr");
	tcgetattr(STDIN_FILENO, &buf);
	if ((buf.c_lflag & (ECHO | ICANON)) || buf.c_cc[VMIN] != 1
		|| buf.c_cc[VTIME] != 0)
		err_exit("Error tcgetattr");
//	tputs(tgetstr("ti", NULL), 0, ft_putc);
	char *term = getenv("TERM");
	tgetent(NULL, term);
}
