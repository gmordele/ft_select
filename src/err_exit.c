/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 01:48:17 by gmordele          #+#    #+#             */
/*   Updated: 2017/05/26 01:01:17 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_select.h"
#include "libft.h"

void	err_exit(char *error)
{
	extern struct termios	g_saved_termios;
	extern int				g_is_saved;

	ft_dprintf(2, "%s\n", error);
	restore_term();
	exit(EXIT_FAILURE);
}
