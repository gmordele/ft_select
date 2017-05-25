/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_termios.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 01:29:13 by gmordele          #+#    #+#             */
/*   Updated: 2017/05/25 02:07:56 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <stdlib.h>

struct termios	save_termios(struct termios *save)
{
	static struct termios	saved;

	if (save != NULL)
		saved = *save;
	return (saved);
}
