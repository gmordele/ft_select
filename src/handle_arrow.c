/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arrow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 17:54:02 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/03 18:03:05 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	handle_arrow(t_info *info, int key)
{
	if (key == KEY_UP)
		cur_move_up(info);
	else if (key == KEY_DOWN)
		cur_move_down(info);
}
