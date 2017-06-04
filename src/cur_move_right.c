/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_move_right.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 18:34:59 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/04 19:39:46 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_select.h"

static void cur_move_right_small(t_info *info)
{
	int new_pos;

	new_pos = info->cur_pos + info->words_col;
	if (new_pos >= info->n_args)
		new_pos = info->cur_pos % info->words_col;
	move_cur(info, info->cur_pos, new_pos);
	info->cur_pos = new_pos;
}

int		last_col(t_info *info, int pos)
{
	return ((same_page(info, pos, info->n_args - 1)
		&& pos / info->words_col
			 == (info->n_args - 1) / info->words_col));
}

void	cur_move_right(t_info *info)
{
	int	new_pos;

	if (info->n_args <= info->words_page)
	{
		cur_move_right_small(info);
		return ;
	}
	if (last_col(info, info->cur_pos))
	{
		info->cur_pos = info->cur_pos % info->words_col;
		print_scr(info);
		return ;
	}
	new_pos = (info->cur_pos + info->words_col >= info->n_args) ?
		info->n_args - 1 : info->cur_pos + info->words_col;
	if (same_page(info, info->cur_pos, new_pos))
	{
		move_cur(info, info->cur_pos, new_pos);
		info->cur_pos = new_pos;
		return ;
	}
	info->cur_pos = new_pos;
	print_scr(info);
}
