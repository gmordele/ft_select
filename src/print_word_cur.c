/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_word_cur.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 14:51:19 by gmordele          #+#    #+#             */
/*   Updated: 2017/05/26 14:57:35 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "libft.h"
#include "ft_select.h"

void	print_word_cur_uns(char *word, int len, int col, int row)
{
	char	*str;
	int		word_len;

	str = tgetstr("cm", NULL);
	tputs(tgoto(str, col, row), 1, tputc);
	ft_printf("{WHI}{BG_BLA}");
	str = tgetstr("us", NULL);
	tputs(str, 1, tputc);
	word_len = ft_printf("%s", word);
	str = tgetstr("ue", NULL);
	tputs(str, 1, tputc);
	while (++word_len <= len)
		ft_printf(" ");
	ft_printf("{RES}");
}

void	print_word_cur_sel(char *word, int len, int col, int row)
{
	char	*str;
	int		word_len;

	str = tgetstr("cm", NULL);
	tputs(tgoto(str, col, row), 1, tputc);
	ft_printf("{BLA}{BG_WHI}");
	str = tgetstr("us", NULL);
	tputs(str, 1, tputc);
	word_len = ft_printf("%s", word);
	str = tgetstr("ue", NULL);
	tputs(str, 1, tputc);
	while (++word_len <= len)
		ft_printf(" ");
	ft_printf("{RES}");
}