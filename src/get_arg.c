/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 14:35:32 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/02 16:20:26 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_select.h"

t_arg_lst *get_arg(t_info *info, int rank)
{
	t_arg_lst	*ret;

	ret = info->arg_lst;
	if (ret == NULL)
		return (NULL);
	if (rank == 0)
		return (ret);
	ret = ret->next;
	while (ret->rank != 0)
	{
		if (ret->rank == rank)
			return (ret);
		ret = ret->next;
	}
	return (NULL);
}
