/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_signals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 10:38:21 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/08 13:02:59 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_select.h"
#include "libft.h"

static void		sigint_handler(int sig)
{
	t_info	*info;

	(void)sig;
	info = sta_info(NULL);
	clean_exit(info);
}

static void		sigstp_handler(int sig)
{
	t_info *info;

	(void)sig;
	info = sta_info(NULL);
	if (signal(SIGTSTP, SIG_DFL) == SIG_ERR)	
		err_exit(info, "Error signal");
	restore_term(info);
	if (signal(SIGTSTP, SIG_DFL) == SIG_ERR)	
		err_exit(info, "Error signal");
}

static void		sigcont_handler(int sig)
{
	t_info *info;


	(void)sig;
	info = sta_info(NULL);
	if (signal(SIGTSTP, sigstp_handler) == SIG_ERR)	
		err_exit(info, "Error signal");
	init_termios(info);
	init_termcap(info);
	get_winsize(info);
	print_scr(info);
}

static void		sigwinch_handler(int sig)
{

	t_info	*info;

	(void)sig;
	info = sta_info(NULL);
	get_winsize(info);
	clean_scr(info);
	print_scr(info);
}

void			init_signals(t_info *info)
{
	int		sig;

	sig = 1;
	while (sig <= 31)
	{
		if (sig != 9 && sig != 17)
			if (signal(sig, sigint_handler) == SIG_ERR)	
				err_exit(info, "Error signal");
		++sig;
	}
	if (signal(SIGTSTP, sigstp_handler) == SIG_ERR)	
		err_exit(info, "Error signal");
	if (signal(SIGCONT, sigcont_handler) == SIG_ERR)	
		err_exit(info, "Error signal");
	if (signal(SIGWINCH, sigwinch_handler) == SIG_ERR)
		err_exit(info, "Error signal");
}