/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_termios.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 00:15:31 by gmordele          #+#    #+#             */
/*   Updated: 2017/05/25 17:04:27 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <unistd.h>
#include "ft_select.h"

struct termios	g_saved_termios;
int				g_is_saved = 0;

static void		save_termios(struct termios saved)
{
	g_saved_termios = saved;
	g_is_saved = 1;
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
}
