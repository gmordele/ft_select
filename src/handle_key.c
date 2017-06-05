/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 17:07:34 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/05 17:20:28 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "libft.h"
#include "ft_select.h"

static void	handle_key_normal(t_info *info, int key)
{
	if (key == KEY_ESC)
		info->exit = 1;
	else if (key == KEY_PAGE_DOWN || key == KEY_PAGE_UP)
			handle_page(info, key);
	else if (key == KEY_UP || key == KEY_DOWN
			 || key == KEY_LEFT || key == KEY_RIGHT)
		handle_arrow(info, key);
	else if (key == KEY_SPACE)
		handle_space(info);
	else if (key == KEY_DEL || key == KEY_BACKSPACE)
		handle_del(info);
}

static void	handle_key_search(t_info *info, int key)
{
	(void)info;
	(void)key;
}

static void	handle_key_blocked(t_info *info, int key)
{
	if (key == KEY_ESC)
		info->exit = 1;
}

void		handle_key(t_info *info, int key)
{
	if (info->state == STATE_BLOCK_NO
		|| info->state == STATE_BLOCK_SE)
		handle_key_blocked(info, key);
	if (info->state == STATE_NORMAL)
		handle_key_normal(info, key);
	if (info->state == STATE_SEARCH)
		handle_key_search(info, key);
}

