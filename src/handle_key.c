/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 17:07:34 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/03 18:44:51 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "libft.h"
#include "ft_select.h"

void	handle_key(t_info *info, int key)
{
	if (key == KEY_ESC)
		info->exit = 1;
	else if (key == KEY_PAGE_DOWN || key == KEY_PAGE_UP)
		handle_page(info, key);
	else if (key == KEY_UP || key == KEY_DOWN
		|| key == KEY_LEFT || key == KEY_RIGHT)
		handle_arrow(info, key);
}
