/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_termcap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 17:34:05 by gmordele          #+#    #+#             */
/*   Updated: 2017/05/26 02:11:27 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <stdlib.h>
#include "ft_select.h"
#include "libft.h"

void	init_termcap(void)
{
	char			*term_type;
	struct winsize	size;
	char			*str;

	if ((term_type = getenv("TERM")) == NULL)
		err_exit("Error getenv");
	if (tgetent(NULL, term_type) <= 0)
		err_exit("Error tgetent");
	size = get_winsize();
	str = tgetstr("ti", NULL);
	tputs(str, size.ws_row, tputc);
	str = tgetstr("vi", NULL);
	tputs(str, 1, tputc);
}
