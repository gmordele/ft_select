/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   same_page.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 18:58:30 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/04 18:58:43 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	same_page(t_info *info, int pos1, int pos2)
{
	return (pos1 / info->words_page == pos2 / info->words_page);
}
