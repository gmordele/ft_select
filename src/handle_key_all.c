/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 09:56:19 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/08 19:48:13 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	select_all(t_info *info)
{
	t_arg_lst *arg_lst;

	arg_lst = info->arg_lst;
	arg_lst->state = SELECTED;
	arg_lst = arg_lst->next;
	while (arg_lst->rank != 0)
	{
		arg_lst->state = SELECTED;
		arg_lst = arg_lst->next;
	}
	info->selected_args = info->n_args;
}

static void	unselect_all(t_info *info)
{
	t_arg_lst *arg_lst;

	arg_lst = info->arg_lst;
	arg_lst->state = UNSELECTED;
	arg_lst = arg_lst->next;
	while (arg_lst->rank != 0)
	{
		arg_lst->state = UNSELECTED;
		arg_lst = arg_lst->next;
	}
	info->selected_args = 0;
}

void		handle_key_all(t_info *info)
{
	if (info->selected_args != info->n_args)
		select_all(info);
	else
		unselect_all(info);
	print_scr(info);
}
