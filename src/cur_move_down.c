/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_move_down.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 18:37:04 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/04 18:37:25 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_select.h"

void	cur_move_down(t_info *info)
{
	t_arg_lst	*arg_lst;
	int			next_rank;

	if ((arg_lst = get_arg(info, info->cur_pos)) == NULL)
		err_exit(info, "Error get_arg");
	next_rank = arg_lst->next->rank;
	if (info->n_args <= info->words_page)
	{
		move_cur(info, info->cur_pos, next_rank);
		info->cur_pos = next_rank;
		return ;
	}
	if (next_rank == 0
		|| info->cur_pos % info->words_page == info->words_page - 1)
	{
		info->cur_pos = next_rank;
		print_scr(info);
		return ;
	}
	move_cur(info, info->cur_pos, next_rank);
	info->cur_pos = next_rank;
}
