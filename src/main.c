/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 23:15:41 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/01 16:43:59 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_select.h"
#include "libft.h"

static  void	main_loop(t_info *info)
{
	ssize_t	n;
	char	buf[1024];
	int		key;

	while (!info->exit)
	{
		if ((n = read(STDIN_FILENO, buf, 1024)) < 0)
			err_exit(info, "Error read");
		key = pressed_key(n, buf);
		if (key == KEY_ESC)
			info->exit = 1;
	}
}

static void		get_len(t_info *info)
{
	t_arg_lst	*p;
	int			len;

	p = info->arg_lst;
	info->len = ft_strlen(p->arg);
	p = p->next;
	while (p->rank != 0)
	{
		len = ft_strlen(p->arg);
		info->len = (len > info->len) ? len : info->len;
		p = p->next;
	}
}

static void		init_info(t_info *info)
{
	info->exit = 0;
	info->is_saved = 0;
	get_winsize(info);
	get_len(info);
	info->words_row = (info->len <= info->col) ?
		1 + (info->col - info->len) / (info->len + 1) : 0;
	info->words_col	= (info->row > 2) ? info->row - 2 : 0;
	info->cur_pos = 2;
}

int				main(int argc, char *argv[])
{
	t_info info;

	if (argc < 2 || argc >= 10000)
	{
		ft_dprintf(2, "Error arguments\n");	
		exit(EXIT_FAILURE);
	}
	make_arg_lst(&info, argc, argv);
	init_info(&info);
	sta_info(&info);
	init_termios(&info);
	init_termcap(&info);
	print_scr(&info);
	main_loop(&info);
	restore_term(&info);
	ft_printf("%d\n", info.words_row);
	return (0);
}
