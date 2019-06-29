/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 11:43:31 by akorol            #+#    #+#             */
/*   Updated: 2019/06/15 11:43:43 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			setting_levels(t_table *tbl, t_node *cur)
{
	int		idx;
	int		flag;

	idx = 0;
	tbl->q[idx] = cur;
	flag = 0;
	while (cur && ft_strcmp(cur->name, tbl->end->name))
	{
		add_to_queue(tbl, cur);
		cur = tbl->q[++idx];
	}
	if (cur && !ft_strcmp(cur->name, tbl->end->name))
		flag = 1;
	tbl->end->level = INT_MAX;
	if (!flag)
		return (-1);
	return (idx);
}

void		set_direction(t_node *part, t_node *root)
{
	int		k;

	k = -1;
	while (part->vert && part->vert[++k])
	{
		if (!ft_strcmp(part->vert[k]->name, root->name) && root->level < part->level)
		{
			delete_from_vert(part, k);
			k--;
		}
	}
}

void		directions(t_table *tbl)
{
	int		i;
	int		j;

	i = -1;
	while (tbl->q[++i])
	{
		j = -1;
		while (tbl->q[i]->vert[++j])
			set_direction(tbl->q[i]->vert[j], tbl->q[i]);
	}
}

void		bad_links(t_table *tbl)
{
	t_node	*node;
	int		i;
	int		j;

	i = -1;
	g_node = NULL;
	while (tbl->q[++i])
	{
		node = tbl->q[i];
		j = -1;
		while (node->vert && node->vert[++j])
		{
			if (node->vert[j]->level == node->level || node->vert[j]->level == -1)
			{
				delete_from_vert(node, j);
				j--;
			}
		}
	}
}