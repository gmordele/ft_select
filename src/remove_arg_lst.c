/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_arg_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmordele <gmordele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 17:08:00 by gmordele          #+#    #+#             */
/*   Updated: 2017/06/05 10:35:56 by gmordele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_select.h"

static void			down_rank(t_arg_lst *ranked)
{
	--(ranked->rank);
	ranked = ranked->next;
	while (ranked->rank != 0)
	{
		--(ranked->rank);
		ranked = ranked->next;
	}
}

static void 		remove_first(t_arg_lst **first)
{
	t_arg_lst	*next;
	t_arg_lst	*prev;

	if ((*first)->next->rank == 0)
	{
		free(*first);
		*first = NULL;
		return ;
	}
	next = (*first)->next;
	prev = (*first)->prev;
	next->prev = prev;
	prev->next = next;
	free(*first);
	*first = next;
	if (next->rank != 0)
		down_rank(next);
}

static t_arg_lst	*get_ranked(t_arg_lst *first, int rank)
{
	t_arg_lst	*p;

	p = first;
	if (rank <= p->prev->rank / 2)
		while (p->rank != rank)
			p = p->next;
	else
		while (p->rank != rank)
			p = p->prev;
	return (p);
}

void				remove_arg_lst(t_info *info, int rank)
{
	t_arg_lst	*p;
	t_arg_lst	*next;
	t_arg_lst	*prev;
	t_arg_lst	**first;

	first = &(info->arg_lst);
	if (*first == NULL || (*first)->prev->rank < rank)
		return ;
	if (rank == 0)
	{
		remove_first(first);
		return ;
	}
	p = get_ranked(*first, rank);
	next = p->next;
	prev = p->prev;
	free(p);
	next->prev = prev;
	prev->next = next;
	if (next->rank != 0)
		down_rank(next);
}
