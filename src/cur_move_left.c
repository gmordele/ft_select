/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_move_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 18:36:37 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/05 10:05:38 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_select.h"

void	cur_move_left(t_info *info)
{
	int	new_pos;

	if (info->cur_pos < info->words_col)
	{
		if (info->cur_pos > (info->n_args - 1) % info->words_col)
			new_pos = info->n_args - 1;
		else
			new_pos = (info->n_args - 1) / info->words_col * info->words_col
				+ info->cur_pos;
	}
	else
		new_pos = info->cur_pos - info->words_col;
	if (same_page(info, info->cur_pos, new_pos))
	{
		move_cur(info, info->cur_pos, new_pos);
		info->cur_pos = new_pos;
	}
	else
	{
		info->cur_pos = new_pos;
		print_scr(info);
	}
}
