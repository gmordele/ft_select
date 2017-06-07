/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_word_cur.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 14:51:19 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/07 10:42:54 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "libft.h"
#include "ft_select.h"

void			print_word_cur_uns(t_info *info, char *word, int row, int col)
{
	char	*str;
	int		word_len;

	str = tgetstr("cm", NULL);
	tputs(tgoto(str, col, row), 1, tputc);
	ft_dprintf(info->fd, "{WHI}{BG_BLA}");
	ft_dprintf(info->fd, "%C", 8594);
	str = tgetstr("us", NULL);
	tputs(str, 1, tputc);
	word_len = ft_dprintf(info->fd, "%s", word) + 1;
	str = tgetstr("ue", NULL);
	tputs(str, 1, tputc);
	while (++word_len <= info->len)
		ft_dprintf(info->fd, " ");
	ft_dprintf(info->fd, "{RES}");
}

void			print_word_cur_sel(t_info *info, char *word, int row, int col)
{
	char	*str;
	int		word_len;

	str = tgetstr("cm", NULL);
	tputs(tgoto(str, col, row), 1, tputc);
	ft_dprintf(info->fd, "{BLA}{BG_WHI}");
	ft_dprintf(info->fd, "%C", 8594);
	str = tgetstr("us", NULL);
	tputs(str, 1, tputc);
	word_len = ft_dprintf(info->fd, "%s", word) + 1;
	str = tgetstr("ue", NULL);
	tputs(str, 1, tputc);
	while (++word_len <= info->len)
		ft_dprintf(info->fd, " ");
	ft_dprintf(info->fd, "{RES}");
}
