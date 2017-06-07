/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_search_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 18:28:48 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/06 19:26:45 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "libft.h"
#include "ft_select.h"

void	handle_search_char(t_info *info, char c)
{
	int pos_cur;

	ft_dprintf(info->fd, "{BG_WHI}{BLA}");
	if (c == KEY_BACKSPACE && info->search_cur > 0)
	{
			pos_cur = info->search_cur + 7;
			tputs(tgoto(tgetstr("cm", NULL),pos_cur , info->row - 1), 1, tputc);
			ft_dprintf(info->fd, " ");
			info->search_buf[--(info->search_cur)] = '\0';
	}
	else if (c != KEY_BACKSPACE)
	{
		if (info->search_cur < info->len - 1)
		{
			pos_cur = info->search_cur + 8;
			tputs(tgoto(tgetstr("cm", NULL),pos_cur , info->row - 1), 1, tputc);
			ft_dprintf(info->fd, "%c", c);
			info->search_buf[info->search_cur] = c;
			++(info->search_cur);
			search_for(info);
		}
	}
	ft_dprintf(info->fd, "{RES}");
}
