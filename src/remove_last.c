/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 11:20:21 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/05 15:25:13 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	remove_word(t_info *info, int rank)
{
	int	row;
	int	col;

	row = rank % info->words_col;
	col = ((rank / info->words_col) % info->words_row)
		* (info->len + 1);
	print_word_uns(" ", info->len, row, col);
}

void		remove_last(t_info *info)
{
	if (info->cur_pos % info->words_page == 0)
	{
		--(info->cur_pos);
		--(info->n_args);
		remove_arg_lst(info, info->cur_pos + 1);
		print_scr(info);
	}
	else
	{
		move_cur(info, info->cur_pos, info->cur_pos - 1);
		remove_word(info, info->cur_pos);
		--(info->cur_pos);
		--(info->n_args);
		remove_arg_lst(info, info->cur_pos + 1);
		print_foot(info);
	}
}
