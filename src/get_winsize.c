/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_winsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 00:39:15 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/08 19:47:44 by gmordele         ###   ########.fr       */
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
	info->words_row = (info->len <= info->col) ?
		1 + (info->col - info->len) / (info->len + 1) : 0;
	info->words_col = (info->row > 2) ? info->row - 2 : 0;
	info->words_page = info->words_col * info->words_row;
}
