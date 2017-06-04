/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_move_up.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 18:37:48 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/04 18:38:02 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_select.h"

void	cur_move_up(t_info *info)
{
	if (info->cur_pos == 0)
	{
		info->cur_pos = info->arg_lst->prev->rank;
		if (info->n_args > info->words_page)
			print_scr(info);
		else
			move_cur(info, 0, info->cur_pos);
	}
	else
	{
		if (info->cur_pos % info->words_page == 0)
		{
			--(info->cur_pos);
			print_scr(info);
		}
		else
		{
			move_cur(info, info->cur_pos, info->cur_pos - 1);
			--(info->cur_pos);
		}
	}
}
