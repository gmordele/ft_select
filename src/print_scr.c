/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 00:58:05 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/01 16:50:12 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "libft.h"

static	void	print_word(t_arg_lst *arg_lst, t_info *info, int row, int col)
{
	if (arg_lst->rank != info->cur_pos)
	{
		if (arg_lst->state == UNSELECTED)
			print_word_uns(arg_lst->arg, info->len, row, col);
		else
			print_word_sel(arg_lst->arg, info->len, row, col);
	}
	else
	{
		if (arg_lst->state == UNSELECTED)
			print_word_cur_uns(arg_lst->arg, info->len, row, col);
		else
			print_word_cur_sel(arg_lst->arg, info->len, row, col);
	}
}

static	void	red_screen(t_info *info)
{
	int	row;
	int	col;

	col = 0;
	row = 0;
	ft_printf("{BG_RED}");
	while (row < info->row)
	{
		while (col++ < info->col)
			ft_printf(" ");
		ft_printf("\n");
		++row;
	}
	ft_printf("{RES}");
}

static	void	print_words(t_info *info)
{
	int			row;
	int			col;
	t_arg_lst	*arg_lst;

	arg_lst = info->arg_lst;
	print_word(arg_lst, info, 0, 0);
	col = 0;
	row = 1;
	if (row == info->row - 2)
	{
		row = 0;
		col += info->len + 1;
	}
	arg_lst= arg_lst->next;
	while (col <= info->col - info->len)
	{
		if (arg_lst->rank != 0)
		{
			print_word(arg_lst, info, row, col);
			arg_lst = arg_lst->next;
		}
		else 
			print_word_uns(" ", info->len, row, col);
		++row;
		if (row == info->row - 2)
		{
			row = 0;
			col += info->len + 1;
		}
	}
}

void 		print_scr(t_info *info)
{
	if (info->words_row == 0 || info->words_col == 0)
		red_screen(info);
	else
		print_words(info);
}

