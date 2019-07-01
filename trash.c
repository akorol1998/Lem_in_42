/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 17:05:08 by akorol            #+#    #+#             */
/*   Updated: 2019/07/01 17:05:23 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			setting_level(t_table *tbl, t_node *cur)
{
	int		end;
	int		idx;

	end = 0;
	idx = 0;
	while (tbl->q[idx] && cur && ft_strcmp(cur->name, tbl->end->name))
	{
		add_to_queue(tbl, cur);
		cur = tbl->q[++idx];
		if (cur && !ft_strcmp(cur->name, tbl->end->name))
			end = 1;
	}
	if (!end && !len_arr(NULL, tbl->path))
		return (-1);
	else if (!end && len_arr(NULL, tbl->path))
		return (0);
	return (idx);
}

int			set_levels(t_table *tbl)
{
	t_node	*cur;
	int		idx;
	int		flag;
	t_pipe	*pip;

	idx = 0;
	flag = 0;
	cur = tbl->nodes;
	pip = cur->branch;
	while (pip)
	{
		if (!pip->node->visited)
			flag = 1;
		pip = pip->next;
	}
	if (!flag)
		return (0);
	tbl->q[idx] = cur;
	return (setting_level(tbl, cur));
}
