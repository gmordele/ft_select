/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 10:08:55 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/05 15:17:21 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"



void	handle_space(t_info *info)
{
	t_arg_lst	*arg_lst;

	if ((arg_lst = get_arg(info, info->cur_pos)) == NULL)
		err_exit(info, "Error get_arg");
	if (arg_lst->state == SELECTED)
	{
		arg_lst->state = UNSELECTED;
		--(info->selected_args);
		cur_move_down(info);
		print_foot(info);
	}
	else
	{
		arg_lst->state = SELECTED;
		++(info->selected_args);
		cur_move_down(info);
		print_foot(info);
	}
}
