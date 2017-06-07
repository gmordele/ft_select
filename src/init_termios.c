/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_termios.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 00:15:31 by gmordele          #+#    #+#             */
/*   Updated: 2017/05/27 16:25:41 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <unistd.h>
#include "ft_select.h"

static void		save_termios(t_info *info, struct termios buf)
{
	info->saved_termios = buf;
	info->is_saved = 1;
}

void			init_termios(t_info *info)
{
	struct termios	buf;

	if (tcgetattr(info->fd, &buf) < 0)
		err_exit(info, "Error tcgetattr");
	save_termios(info, buf);
	buf.c_lflag &= ~(ECHO | ICANON);
	buf.c_cc[VMIN] = 1;
	buf.c_cc[VTIME] = 0;
	buf.c_cc[VSTOP] = _PC_VDISABLE;
	if (tcsetattr(info->fd, TCSANOW, &buf) < 0)
		err_exit(info, "Error tcsetattr");
	tcgetattr(info->fd, &buf);
	if ((buf.c_lflag & (ECHO | ICANON)) || buf.c_cc[VMIN] != 1
		|| buf.c_cc[VTIME] != 0)
		err_exit(info, "Error tcgetattr");
}
