/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_quit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 01:48:17 by gmordele          #+#    #+#             */
/*   Updated: 2017/05/25 14:07:41 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_select.h"
#include "libft.h"

void	err_exit(char *error)
{
	extern struct termios	saved_termios;
	extern int				is_saved;

	ft_dprintf(2, "%s\n", error);
	if (is_saved)
		tcsetattr(STDIN_FILENO, TCSANOW, &saved_termios);
	exit(EXIT_FAILURE);
}
