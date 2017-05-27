/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 01:48:17 by gmordele          #+#    #+#             */
/*   Updated: 2017/05/27 01:33:24 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_select.h"
#include "libft.h"

void	err_exit(t_info *info, char *error)
{
	restore_term(info);
	ft_dprintf(2, "%s\n", error);
	exit(EXIT_FAILURE);
}
