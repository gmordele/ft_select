/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_search_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 18:28:48 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/08 20:12:22 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "libft.h"
#include "ft_select.h"

static void	is_found(t_info *info, int result)
{
	tputs(tgoto(tgetstr("cm", NULL), 8, info->row - 1), 1, tputc);
	if (result)
	{
		ft_dprintf(info->fd, "{BG_WHI}{BLA}%s", info->search_buf);
		info->is_found = 1;
	}
	else
	{
		ft_dprintf(info->fd, "{BG_RED}{BLA}%s", info->search_buf);
		info->is_found = 0;
	}
	ft_dprintf(info->fd, "{RES}");
}

void		handle_search_char(t_info *info, char c)
{
	int pos_cur;

	ft_dprintf(info->fd, "{BG_WHI}{BLA}");
	if (c == KEY_BACKSPACE && info->search_cur > 0)
	{
		pos_cur = info->search_cur + 7;
		tputs(tgoto(tgetstr("cm", NULL), pos_cur, info->row - 1), 1, tputc);
		ft_dprintf(info->fd, " ");
		info->search_buf[--(info->search_cur)] = '\0';
		is_found(info, search_for(info));
	}
	else if (c != KEY_BACKSPACE)
	{
		if (info->search_cur < info->len - 1)
		{
			pos_cur = info->search_cur + 8;
			tputs(tgoto(tgetstr("cm", NULL), pos_cur, info->row - 1), 1, tputc);
			info->search_buf[info->search_cur] = c;
			++(info->search_cur);
			is_found(info, search_for(info));
		}
	}
	ft_dprintf(info->fd, "{RES}");
}
