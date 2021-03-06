/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 00:58:05 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/08 20:04:47 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "libft.h"

static	void	print_word(t_arg_lst *arg_lst, t_info *info, int row, int col)
{
	if (arg_lst->rank != info->cur_pos)
	{
		if (arg_lst->state == UNSELECTED)
			print_word_uns(info, arg_lst->arg, row, col);
		else
			print_word_sel(info, arg_lst->arg, row, col);
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

static void		print_words(t_info *info, t_arg_lst *first)
{
	int			row;
	int			col;
	t_arg_lst	*arg_lst;

	arg_lst = first;
	print_word(arg_lst, info, 0, 0);
	col = 0;
	row = 1;
	update_row_col(&row, &col, info);
	arg_lst = arg_lst->next;
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

static void		print_page(t_info *info, int page)
{
	int			first_rank;
	t_arg_lst	*first;

	first_rank = page * info->words_page;
	if ((first = get_arg(info, first_rank)) == NULL)
		err_exit(info, "Error get_arg");
	print_words(info, first);
}

void			print_scr(t_info *info)
{
	int page;

	if (info->words_page == 0 || info->col < 41
		|| info->col < info->len + 7)
	{
		red_screen(info);
		if (info->state == STATE_NORMAL)
			info->state = STATE_BLOCK_NO;
		else if (info->state == STATE_SEARCH)
			info->state = STATE_BLOCK_SE;
	}
	else
	{
		if (info->state == STATE_BLOCK_NO)
			info->state = STATE_NORMAL;
		else if (info->state == STATE_BLOCK_SE)
			info->state = STATE_SEARCH;
		page = info->cur_pos / info->words_page;
		print_page(info, page);
		print_foot(info);
		if (info->state == STATE_SEARCH)
			show_search_bar(info);
	}
}
