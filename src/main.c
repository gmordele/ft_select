/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 23:15:41 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/04 14:43:11 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_select.h"
#include "libft.h"
#include "locale.h"

static  void	main_loop(t_info *info)
{
	ssize_t	n;
	char	buf[1024];
	int		key;

	while (!info->exit)
	{
		if ((n = read(STDIN_FILENO, buf, 1024)) < 0)
			err_exit(info, "Error read");
		/*
		for (int i = 0; i < n; ++i)
			ft_printf("%d ", buf[i]);
		ft_printf("\n");
		*/
		key = pressed_key(n, buf);
		handle_key(info, key);
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
	++info->len;
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
	info->words_page = info->words_col * info->words_row;
	info->cur_pos = 0;
	get_n_args(info);
}

int				main(int argc, char *argv[])
{
	t_info info;

	setlocale(LC_ALL, "");
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
	return (0);
}
