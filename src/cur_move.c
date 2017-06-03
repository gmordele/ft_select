/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 18:03:37 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/03 20:10:58 by gmordele         ###   ########.fr       */
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

void	cur_move_down(t_info *info)
{
	t_arg_lst *arg_lst;


	if ((arg_lst = get_arg(info, info->cur_pos)) == NULL)
		err_exit(info, "Error get_arg");
	if (info->n_args <= info->words_page)
	{
		move_cur(info, info->cur_pos, arg_lst->next->rank);
		info->cur_pos = arg_lst->next->rank;
	}
	else
	{
		
	}
}
