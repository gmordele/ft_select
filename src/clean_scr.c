/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_scr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 12:46:21 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/08 17:00:37 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "libft.h"

void	clean_scr(t_info *info)
{
	ft_dprintf(info->fd, "{BG_BLA}");
	ft_dprintf(info->fd, "%*c", info->row * info->col, ' ');
	ft_dprintf(info->fd, "{RES}");
}
