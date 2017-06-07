/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_winsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 00:39:15 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/07 11:18:18 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "ft_select.h"

void	get_winsize(t_info *info)
{
	struct winsize	size;

	if (ioctl(info->fd, TIOCGWINSZ, &size) < 0)
		err_exit(info, "Error ioctl");
	info->col = size.ws_col;
	info->row = size.ws_row;
}
