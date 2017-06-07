/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 15:47:39 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/05 17:32:19 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "libft.h"

void	red_screen(t_info *info)
{
	int i;
	int lim;

	ft_dprintf(info->fd, "{BG_RED}");
	lim = info->row * info->col;
	i = 0;
	while (i++ < lim)
		ft_dprintf(info->fd, " ");
	ft_dprintf(info->fd, "{RES}");
}
