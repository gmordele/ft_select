/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_search_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 18:28:48 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/05 18:57:24 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "libft.h"
#include "ft_select.h"

void	handle_search_char(t_info *info, char c)
{
	int pos_cur;

	pos_cur = info->search_cur + 8;
	tputs(tgoto(tgetstr("cm", NULL),pos_cur , info->row - 1), 1, tputc);
	ft_printf("{BG_WHI}{BLA}");
	if (c == KEY_BACKSPACE)
		ft_printf("%c", 127);
	else
		ft_printf("%c", c);
	if (c == KEY_BACKSPACE)
		--(info->search_cur);
	else
		++(info->search_cur);
	ft_printf("{RED}");
}
