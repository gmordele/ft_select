/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_foot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 10:23:26 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/08 20:13:21 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "ft_select.h"
#include "libft.h"

static void	selected_elements(t_info *info)
{
	ft_dprintf(info->fd, "selected element(s): %-4d/%4d", info->selected_args,
		info->n_args);
}

static void	pages(t_info *info)
{
	ft_dprintf(info->fd, "%-4d/%4d", info->cur_pos / info->words_page + 1,
			(info->n_args - 1) / info->words_page + 1);
}

void		print_foot(t_info *info)
{
	int diff;
	int	row;

	row = info->row - 2;
	tputs(tgoto(tgetstr("cm", NULL), 0, row), 1, tputc);
	ft_dprintf(info->fd, "{BG_WHI}{BLA}");
	selected_elements(info);
	diff = info->col - 39;
	while (diff-- > 0)
		ft_dprintf(info->fd, " ");
	pages(info);
	ft_dprintf(info->fd, "{RES}");
}
