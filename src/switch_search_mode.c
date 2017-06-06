/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_search_mode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 17:43:45 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/06 19:05:29 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "ft_select.h"
#include "libft.h"

void		show_search_bar(t_info *info)
{
	int i;

	tputs(tgoto(tgetstr("cm", NULL),0 , info->row - 1), 1, tputc);
	ft_printf("{BG_WHI}{BLA}");
	i = ft_printf("search: %s", info->search_buf);
	while (i++ < info->col)
		ft_printf(" ");
	ft_printf("{RES}");
}

static void	hide_search_bar(t_info *info)
{
	int	i;

	tputs(tgoto(tgetstr("cm", NULL),0 , info->row - 1), 1, tputc);
	i = 0;
	ft_printf("{BG_BLA}");
	while (i++ < info->col)
		ft_printf(" ");
	ft_printf("{RES}");
}

void		switch_search_mode(t_info *info)
{
	info->search_cur = 0;
	ft_bzero(info->search_buf, info->len);
	if (info->state == STATE_NORMAL)
	{
		info->state = STATE_SEARCH;
		show_search_bar(info);
	}
	else if (info->state == STATE_SEARCH)
	{
		info->state = STATE_NORMAL;
		hide_search_bar(info);
	}
}
