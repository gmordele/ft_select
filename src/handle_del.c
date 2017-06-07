/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 10:29:13 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/07 10:46:38 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static	void	print_word(t_arg_lst *arg_lst, t_info *info, int row, int col)
{
	if (arg_lst->rank != info->cur_pos)
	{
		if (arg_lst->state == UNSELECTED)
			print_word_uns(info, arg_lst->arg, row, col);
		else
			print_word_sel(info, arg_lst->arg,  row, col);
	}
	else
	{
		if (arg_lst->state == UNSELECTED)
			print_word_cur_uns(info, arg_lst->arg, row, col);
		else
			print_word_cur_sel(info, arg_lst->arg, row, col);
	}
}

static void		update_row_col(int *row, int *col, t_info *info)
{
	if (*row == info->row - 2)
	{
		*row = 0;
		*col += info->len + 1;
	}
}

static	void	print_words(t_info *info, t_arg_lst *pos)
{
	int			row;
	int			col;
	t_arg_lst	*arg_lst;

	arg_lst = pos;
	row = info->cur_pos % info->words_col;
	col = ((info->cur_pos / info->words_col) % info->words_row)
		* (info->len + 1);
	print_word(arg_lst, info, row, col);
	++row;
	update_row_col(&row, &col, info);
	arg_lst= arg_lst->next;
	while (col <= info->col - info->len)
	{
		if (arg_lst->rank != 0)
		{
			print_word(arg_lst, info, row, col);
			arg_lst = arg_lst->next;
		}
		else
			print_word_uns(info, " ", row, col);
		++row;
		update_row_col(&row, &col, info);
	}
}

static void	remove(t_info *info)
{
	t_arg_lst *pos;

	remove_arg_lst(info, info->cur_pos);
	--(info->n_args);
	if ((pos = get_arg(info, info->cur_pos)) == NULL)
		err_exit(info, "Error get_arg");
	print_words(info, pos);
	print_foot(info);
}

void		handle_del(t_info *info)
{
	if (info->n_args <= 1)
		info->exit = 1;
	else
	{
		if (info->cur_pos == info->n_args - 1)
			remove_last(info);
		else
			remove(info);
	}
}
