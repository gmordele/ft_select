/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_term.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 15:40:24 by gmordele          #+#    #+#             */
/*   Updated: 2017/05/27 12:17:43 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <term.h>
#include <unistd.h>
#include "ft_select.h"

void	restore_term(t_info *info)
{
	char					*str;

	str = tgetstr("te", NULL);
	tputs(str, info->row, tputc);
	str = tgetstr("ve", NULL);
	tputs(str, 1, tputc);
	if (info->is_saved)
		if (tcsetattr(info->fd, TCSANOW, &info->saved_termios) < 0)
			err_exit(info, "Error tcsetattr");
}
