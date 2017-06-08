/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_page.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 14:15:57 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/08 19:48:45 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	handle_page_up(t_info *info)
{
	int	new_pos;

	new_pos = info->cur_pos - info->cur_pos % info->words_page
		- info->words_page;
	if (new_pos >= 0)
	{
		info->cur_pos = new_pos;
		print_scr(info);
	}
}

static void	handle_page_down(t_info *info)
{
	int	new_pos;

	new_pos = info->cur_pos - info->cur_pos % info->words_page
		+ info->words_page;
	if (new_pos < info->n_args)
	{
		info->cur_pos = new_pos;
		print_scr(info);
	}
}

void		handle_page(t_info *info, int key)
{
	if (key == KEY_PAGE_UP)
		handle_page_up(info);
	else if (key == KEY_PAGE_DOWN)
		handle_page_down(info);
}
