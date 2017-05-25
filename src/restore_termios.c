/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_termios.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 15:40:24 by gmordele          #+#    #+#             */
/*   Updated: 2017/05/25 16:33:36 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <unistd.h>
#include "ft_select.h"
#include <stdio.h>

void	restore_termios(void)
{
	extern struct termios	saved_termios;
	extern int				is_saved;
	printf("resore\n");
	if (is_saved)
		if (tcsetattr(STDIN_FILENO, TCSANOW, &saved_termios) < 0)
			err_exit("Error tcsetattr");
}
