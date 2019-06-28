/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 11:10:11 by akorol            #+#    #+#             */
/*   Updated: 2019/06/06 11:10:23 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


int			launch_algorithm(t_table *tbl)
{
	t_node	*curr;
	int		idx;

	curr = tbl->nodes;
	ft_putstr("node before ");
	while ((idx = set_levels(tbl)))
	{
		if (idx == -1)
		{
			printf("There are no available paths to an end Not enough info, can't reach end\n"); // One ending
			return (0);
		}
		printf("BABY\n");
		data_tunage(tbl);
		for(int k = 0;tbl->end->vert[k];k++)
			printf("End vertecies %s it's level %d\n", tbl->end->vert[k]->name, tbl->end->vert[k]->level);
		fill_paths(tbl);
		add_branches(tbl);
		save_links(tbl);
	}
	if (!idx)
	{
		printf("Start has no linkage or all available paths are taken\n");
		return (0);
	}
	else
		printf("good\n");
	return (1);
}

void		add_to_queue(t_table *tbl, t_node *cur)
{
	int		j;
	int		i;
	int		flag;
	int		idx;

	idx = -1;
	j = -1;
	while (tbl->q[++idx])
		;
	while (cur->vert[++j])
	{
		i = -1;
		flag = 1;
		while (tbl->q[++i])
		{
			if (cur->vert[j]->visited || !ft_strcmp(tbl->q[i]->name, cur->vert[j]->name))
				flag = 0;
		}
		if (flag)
		{
			// printf("name is {%s}\n", cur->name);
			tbl->q[idx] = cur->vert[j];
			// cur->vert[j]->prev = cur;
			cur->vert[j]->level = cur->level + 1;
			idx++;
		}
	}
}

int			set_levels(t_table *tbl)
{
	t_node	*cur;
	int		idx;
	int		flag;
	int		i;

	idx = 0;
	flag = 0;
	i = -1;
	cur = tbl->nodes;
	cur->level = 0;
	while (cur->vert[++i])
	{
		if (!cur->vert[i]->visited)
			flag = 1;
	}
	if (!flag)
		return (0);
	return (setting_levels(tbl, cur));
}