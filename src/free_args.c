/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 10:56:30 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/08 11:05:26 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_select.h"

void	free_args(t_info *info)
{
	t_arg_lst	*p1;
	t_arg_lst	*p2;

	if (info == NULL || info->arg_lst == NULL)
		err_exit(info, "Error free_args");
	p1 = info->arg_lst->next;
	info->arg_lst = NULL;
	while (p1->rank != 0)
	{
		p2 = p1->next;
		free(p1);
		p1 = p2;
	}
	free(p1);
}
