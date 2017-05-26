/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 01:37:51 by gmordele          #+#    #+#             */
/*   Updated: 2017/05/26 02:10:44 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "libft.h"
#include "ft_select.h"

void	print_word(char *word, int len, int col, int row)
{
	char	*str;
	int		word_len;

	(void)len;
	str = tgetstr("cm", NULL);
	tputs(tgoto(str, col, row), 1, tputc);
	word_len = ft_printf("%s", word);
	while (++word_len <= len)
		ft_printf(" ");
}
