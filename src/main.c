/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 23:15:41 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/08 17:53:18 by gmordele         ###   ########.fr       */
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
		if ((n = read(info->fd, buf, 1024)) < 0)
			err_exit(info, "Error read");
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
	get_valid_fd(info);
	get_len(info);
	get_winsize(info);
	info->cur_pos = 0;
	get_n_args(info);
	info->selected_args = 0;
	info->state = STATE_NORMAL;
	info->search_cur = 0;
	if((info->search_buf = (char *)malloc(sizeof(char) * info->len)) == NULL)
		err_exit(info, "Error malloc");
	ft_bzero(info->search_buf, info->len);
	info->print = 0;
}

static void		print_args(t_info *info)
{
	t_arg_lst	*arg_lst;
	int			first;

	if (info->arg_lst == NULL)
		err_exit(info, "Error print_args");
	arg_lst = info->arg_lst;
	first = 1;
	if (arg_lst->state == SELECTED)
	{
		first = 0;
		ft_printf("%s", arg_lst->arg);
	}
	arg_lst = arg_lst->next;
	while (arg_lst->rank != 0)
	{
		if (arg_lst->state == SELECTED)
		{
			if (first == 1)
				first = 0;
			else
				ft_printf(" ", arg_lst->arg);
			ft_printf("%s", arg_lst->arg);
		}
		arg_lst = arg_lst->next;
	}
}

int				main(int argc, char *argv[])
{
	t_info info;

	if (argc < 2 || argc >= 10000)
	{
		ft_dprintf(2, "Error arguments\n");	
		exit(EXIT_FAILURE);
	}
	setlocale(LC_ALL, "");
	make_arg_lst(&info, argc, argv);
	init_info(&info);
	sta_info(&info);
	init_termios(&info);
	init_termcap(&info);
	init_signals(&info);
	print_scr(&info);
	main_loop(&info);
	restore_term(&info);
	if (info.print)
		print_args(&info);
	free_args(&info);
	return (0);
}
