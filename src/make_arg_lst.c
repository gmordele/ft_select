/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_arg_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 14:57:42 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/08 20:00:00 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_select.h"
#include "libft.h"

static t_arg_lst	*new_arg(t_info *info, char *arg, t_arg_lst *prev, int rank)
{
	t_arg_lst	*new;

	if ((new = (t_arg_lst *)malloc(sizeof(t_arg_lst))) == NULL)
		err_exit(info, "Error malloc");
	new->next = NULL;
	new->prev = prev;
	new->arg = arg;
	new->rank = rank;
	new->state = UNSELECTED;
	return (new);
}

static void			add_arg(t_info *info, t_arg_lst **first, char *arg)
{
	t_arg_lst	*p;
	int			rank;

	if (*first == NULL)
	{
		*first = new_arg(info, arg, NULL, 0);
		return ;
	}
	p = *first;
	rank = 1;
	while (p->next != NULL)
	{
		p = p->next;
		++rank;
	}
	p->next = new_arg(info, arg, p, rank);
}

void				make_arg_lst(t_info *info, int argc, char **argv)
{
	int			i;
	t_arg_lst	*first;
	t_arg_lst	*p;

	first = NULL;
	i = 1;
	while (i < argc)
		add_arg(info, &first, argv[i++]);
	p = first;
	while (p->next != NULL)
		p = p->next;
	p->next = first;
	first->prev = p;
	info->arg_lst = first;
}
