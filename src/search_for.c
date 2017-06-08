/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_for.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 18:38:17 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/08 20:07:37 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "libft.h"

void	search_for_next(t_info *info)
{
	int			current;
	t_arg_lst	*arg_lst;

	current = info->cur_pos;
	if ((arg_lst = get_arg(info, current)) == NULL)
		err_exit(info, "Error arg_lst");
	if (strstr(arg_lst->arg, info->search_buf) != arg_lst->arg)
		return ;
	arg_lst = arg_lst->next;
	while (arg_lst->rank != current)
	{
		if (strstr(arg_lst->arg, info->search_buf) == arg_lst->arg)
		{
			info->cur_pos = arg_lst->rank;
			if (same_page(info, info->cur_pos, current))
				move_cur(info, current, info->cur_pos);
			else
				print_scr(info);
			return ;
		}
		arg_lst = arg_lst->next;
	}
}

int		search_for(t_info *info)
{
	int			current;
	t_arg_lst	*arg_lst;

	current = info->cur_pos;
	if ((arg_lst = get_arg(info, current)) == NULL)
		err_exit(info, "Error arg_lst");
	if (strstr(arg_lst->arg, info->search_buf) == arg_lst->arg)
		return (1);
	arg_lst = arg_lst->next;
	while (arg_lst->rank != current)
	{
		if (strstr(arg_lst->arg, info->search_buf) == arg_lst->arg)
		{
			info->cur_pos = arg_lst->rank;
			if (same_page(info, info->cur_pos, current))
				move_cur(info, current, info->cur_pos);
			else
				print_scr(info);
			return (1);
		}
		arg_lst = arg_lst->next;
	}
	return (0);
}
