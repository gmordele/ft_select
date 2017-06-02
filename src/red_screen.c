/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 15:47:39 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/02 15:48:04 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "libft.h"

void	red_screen(t_info *info)
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
