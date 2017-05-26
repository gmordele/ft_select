/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 23:15:41 by gmordele          #+#    #+#             */
/*   Updated: 2017/05/26 02:07:44 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_select.h"
#include "libft.h"

static void print_screen(void)
{
	print_word("salut", 7, 0, 0);
	print_word("ca va ?", 7, 0, 1);
	print_word("1111111", 7, 0, 1);
}

static void	main_loop(void)
{
	ssize_t	n;
	char	buf[1024];
	int		exit;
	int		key;

	exit = 0;
	while (!exit)
	{
		if ((n = read(STDIN_FILENO, buf, 1024)) < 0)
			err_exit("Error read");
		key = pressed_key(n, buf);
		if (key == KEY_ESC)
			exit = 1;
	}
}

int			main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	init_termios();
	init_termcap();
	print_screen();
	main_loop();
	restore_term();
	return (0);
}
