/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_n_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 14:17:53 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/03 15:03:33 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	get_n_args(t_info *info)
{
	if (info == NULL)
		err_exit(info, "Error get_n_args");
	if (info->arg_lst == NULL)
		err_exit(info, "Error get_n_args");
	if (info->arg_lst->prev == NULL)
		err_exit(info, "Error get_n_args");
	info->n_args = info->arg_lst->prev->rank + 1;
}
