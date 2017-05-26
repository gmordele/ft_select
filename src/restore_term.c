/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_term.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 15:40:24 by gmordele          #+#    #+#             */
/*   Updated: 2017/05/26 02:12:31 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <term.h>
#include <unistd.h>
#include "ft_select.h"

void	restore_term(void)
{
	extern struct termios	g_saved_termios;
	extern int				g_is_saved;
	struct winsize			size;
	char					*str;

	size = get_winsize();
	str = tgetstr("te", NULL);
	tputs(str, size.ws_row, tputc);
	str = tgetstr("ve", NULL);
	tputs(str, 1, tputc);
	if (g_is_saved)
		if (tcsetattr(STDIN_FILENO, TCSANOW, &g_saved_termios) < 0)
			err_exit("Error tcsetattr");
}
