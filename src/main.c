/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 23:15:41 by gmordele          #+#    #+#             */
/*   Updated: 2017/05/25 16:33:52 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include <termios.h>
#include <unistd.h>
#include "ft_select.h"
#include "libft.h"

int		main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	init_termios();
//	sleep(10);
	while (1);
//	restore_termios();
	return (0);
}
