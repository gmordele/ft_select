/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_valid_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 10:25:22 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/07 10:29:55 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "ft_select.h"

void	get_valid_fd(t_info *info)
{
	char *name;

	if (isatty(1))
		info->fd = 1;
	else
	{
		if ((name = ttyname(2)) == NULL)
			err_exit(info, "Error ttyname");
		if ((info->fd = open(name, O_WRONLY)) < 0)
			err_exit(info, "Error open");
	}
}
