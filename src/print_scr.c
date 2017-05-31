/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 00:58:05 by gmordele          #+#    #+#             */
/*   Updated: 2017/05/31 21:37:22 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "libft.h"

static void		red_screen(t_info *info)
{
	int	row;
	int	col;

	col = 0;
	row = 0;
	while (row < info->row)
	{
		while (col++ < info->col - 2)
			ft_printf("{BG_RED} ");
		ft_printf("\n");
		++row;
	}
	ft_printf("{RES}");
}

static void		print_words(t_info *info)
{
	int			row;
	int			col;
	t_arg_lst	*arg_lst;

	arg_lst = info->arg_lst;
	print_word_uns(arg_lst->arg, info->len, 0, 0);
	col = 0;
	row = 1;
	arg_lst= arg_lst->next;
	while (arg_lst->rank != 0)
	{
		if (row == info->row - 2)
		{
			row = 0;
			col += info->len + 1;
		}
		print_word_uns(arg_lst->arg, info->len, row, col);
		++row;
		arg_lst = arg_lst->next;
	}
}

void 			print_scr(t_info *info)
{
	if (info->words_row == 0 || info->words_col == 0)
		red_screen(info);
	else
		print_words(info);
}

