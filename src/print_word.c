/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 01:37:51 by gmordele          #+#    #+#             */
/*   Updated: 2017/05/31 21:30:07 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "libft.h"
#include "ft_select.h"

void	print_word_sel(char *word, int len, int col, int row)
{
	char	*str;
	int		word_len;

	str = tgetstr("cm", NULL);
	tputs(tgoto(str, row, col), 1, tputc);
	ft_printf("{BLA}{BG_WHI}");
	word_len = ft_printf("%s", word);
	while (++word_len <= len)
		ft_printf(" ");
	ft_printf("{RES}");
}

void	print_word_uns(char *word, int len, int col, int row)
{
	char	*str;
	int		word_len;

	str = tgetstr("cm", NULL);
	tputs(tgoto(str, row, col), 1, tputc);
	ft_printf("{WHI}{BG_BLA}");
	word_len = ft_printf("%s", word);
	while (++word_len <= len)
		ft_printf(" ");
	ft_printf("{RES}");
}
