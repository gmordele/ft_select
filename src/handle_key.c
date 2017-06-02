/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 17:07:34 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/02 17:50:30 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "libft.h"
#include "ft_select.h"

void	handle_key(t_info *info, int key)
{
	if (key == KEY_ESC)
		info->exit = 1;
	if (key == KEY_PAGE_DOWN)
	{
		info->cur_pos = info->cur_pos / info->words_page + info->words_page;
		print_scr(info);
	}
	if (key == KEY_PAGE_UP)
	{
		info->cur_pos = info->cur_pos / info->words_page - info->words_page;
		print_scr(info);
	}
}

