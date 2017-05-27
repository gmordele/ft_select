/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sta_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 23:35:18 by gmordele          #+#    #+#             */
/*   Updated: 2017/05/27 00:15:26 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_select.h"

t_info			*sta_info(t_info *info)
{
	static t_info	*sinfo;

	if (info != NULL)
		sinfo = info;
	return (sinfo);
}
