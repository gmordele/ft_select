/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 01:37:51 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/07 11:00:02 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "libft.h"
#include "ft_select.h"

void			print_word_uns(t_info *info, char *word, int row, int col)
{
	char	*str;
	int		word_len;

	str = tgetstr("cm", NULL);
	tputs(tgoto(str, col, row), 1, tputc);
	ft_dprintf(info->fd, "{WHI}{BG_BLA}");
	ft_dprintf(info->fd, " ");
	word_len = ft_dprintf(info->fd, "%s", word) + 1;
	while (++word_len <= info->len)
		ft_dprintf(info->fd, " ");
	ft_dprintf(info->fd, "{RES}");
}

void			print_word_sel(t_info *info, char *word, int row, int col)
{
	char	*str;
	int		word_len;

	str = tgetstr("cm", NULL);
	tputs(tgoto(str, col, row), 1, tputc);
	ft_dprintf(info->fd, "{BLA}{BG_WHI}");
	ft_dprintf(info->fd, " ");
	word_len = ft_dprintf(info->fd, "%s", word) + 1;
	while (++word_len <= info->len)
		ft_dprintf(info->fd, " ");
	ft_dprintf(info->fd, "{RES}");
}
