/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_scr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 12:46:21 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/08 12:48:26 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "libft.h"

void	clean_scr(t_info *info)
{
	int i;
	int lim;

	ft_dprintf(info->fd, "{BG_BLA}");
	lim = info->row * info->col;
	i = 0;
	while (i++ < lim)
		ft_dprintf(info->fd, " ");
	ft_dprintf(info->fd, "{RES}");
}
