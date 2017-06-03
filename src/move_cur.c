/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 18:54:23 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/03 19:46:07 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_select.h"

static void	unselect_cur(t_info *info, int pos, int row, int col)
{
	t_arg_lst	*arg_lst;

	if ((arg_lst = get_arg(info, pos)) == NULL)
		err_exit(info, "Error get_arg");
	if (arg_lst->state == SELECTED)
		print_word_sel(arg_lst->arg, info->len, row, col);
	else
		print_word_uns(arg_lst->arg, info->len, row, col);
}

 void	select_cur(t_info *info, int pos, int row, int col)
{
	t_arg_lst	*arg_lst;

	if ((arg_lst = get_arg(info, pos)) == NULL)
		err_exit(info, "Error get_arg");
	if (arg_lst->state == SELECTED)
		print_word_cur_sel(arg_lst->arg, info->len, row, col);
	else
		print_word_cur_uns(arg_lst->arg, info->len, row, col);
}

void		move_cur(t_info *info, int pos_cur1, int pos_cur2)
{
	int	row1;
	int	row2;
	int	col1;
	int	col2;

	row1 = pos_cur1 % info->words_col;
	col1 = ((pos_cur1 / info->words_col) % info->words_row) * (info->len + 1);
	row2 = pos_cur2 % info->words_col;
	col2 = ((pos_cur2 / info->words_col) % info->words_row) * (info->len + 1);
	unselect_cur(info, pos_cur1, row1, col1);
	select_cur(info, pos_cur2, row2, col2);
}
