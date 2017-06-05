/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 15:47:39 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/05 17:29:56 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "libft.h"

void	red_screen(t_info *info)
{
	int	row;
	int	col;

	/*
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
	*/

	ft_printf("{BG_RED}");
	(void)col;
	(void)row;
	int c;
	int all = info->row * info->col;
	for (c = 0; c < all; ++c)
		ft_printf(" ");

	ft_printf("{RES}");
}
