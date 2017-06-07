/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_termcap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 17:34:05 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/07 11:25:00 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <stdlib.h>
#include "ft_select.h"
#include "libft.h"

void	init_termcap(t_info *info)
{
	char			*term_type;
	char			*str;

	if ((term_type = getenv("TERM")) == NULL)
		err_exit(info, "Error getenv");
	if (tgetent(NULL, term_type) <= 0)
		err_exit(info, "Error tgetent");
	str = tgetstr("ti", NULL);
	tputs(str, info->row, tputc);
	str = tgetstr("vi", NULL);
	tputs(str, 1, tputc);
}
