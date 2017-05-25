/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_quit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 01:48:17 by gmordele          #+#    #+#             */
/*   Updated: 2017/05/25 02:08:45 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_select.h"
#include "libft.h"

void	err_quit(char *error)
{
	struct termios	saved;

	ft_dprintf(2, "%s\n", error);
	saved = save_termios(NULL);
	tcsetattr(STDIN_FILENO, TCSANOW, &saved);
	exit(EXIT_FAILURE);
}
