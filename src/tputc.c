/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tputc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 00:49:06 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/07 11:57:00 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_select.h"

int		tputc(int c)
{
	static t_info *info = NULL;

	if (info == NULL)
		info = sta_info(NULL);
	write(info->fd, &c, 1);
	return (1);
}
