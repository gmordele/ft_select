/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pressed_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 19:12:30 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/05 18:31:21 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	single_char(char c)
{
	if (c == 10)
		return (KEY_RETURN);
	if (c == 32)
		return (KEY_SPACE);
	if (c == 27)
		return (KEY_ESC);
	if (c == 127)
		return (KEY_BACKSPACE);
	if (c == 19)
		return (KEY_CTRL_S);
	if (c >= 32 && c <= 126)
		return (c);
	return (-1);
}

static int	arrow_key(char *buf)
{
	if (buf[0] == 27)
		if (buf[1] == 91)
		{
			if (buf[2] == 65)
				return (KEY_UP);
			if (buf[2] == 66)
				return (KEY_DOWN);
			if (buf[2] == 68)
				return (KEY_LEFT);
			if (buf[2] == 67)
				return (KEY_RIGHT);
		}
	return (-1);
}

static int	spe_key(char *buf)
{
	if (buf[0] == 27 && buf[1] == 91
		&& buf[3] == 126)
	{
		if (buf[2] == 51)
			return (KEY_DEL);
		if (buf[2] == 54)
			return (KEY_PAGE_DOWN);
		if (buf[2] == 53)
			return (KEY_PAGE_UP);
	}
	return (-1);
}

int			pressed_key(int n, char *buf)
{
	if (n == 1)
		return (single_char(*buf));
	if (n == 3)
		return (arrow_key(buf));
	if (n == 4)
		return (spe_key(buf));
	return (-1);
}
