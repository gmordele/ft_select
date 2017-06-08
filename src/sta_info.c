/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sta_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 23:35:18 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/08 20:10:13 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_select.h"

t_info	*sta_info(t_info *info)
{
	static t_info	*sinfo = NULL;

	if (info != NULL)
		sinfo = info;
	else
	{
		if (sinfo == NULL)
			err_exit(info, "Error sta_info");
	}
	return (sinfo);
}
