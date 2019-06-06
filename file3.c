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

int			list_len(char **list)
{
	int		i;

	i = -1;
	while(list[++i])
		;
	return (i);
}

int			calculate_dist(t_node *curr, t_table *tbl)
{
	t_pipe	*pip;
	t_node	*contrl;

	tbl = NULL; // HHHHHHEEEEEYYYYyyyyy !!!!!
	if (curr->branch)
	{
		pip = curr->branch;
		if (pip->node && !pip->node->visited)
		{
			contrl = pip->node;
			while (pip)
			{
				pip = pip->next;
				// if (pip->node->current < contrl->current)

			}
		}
	}
	return (1);
}

int			launch_algorithm(t_table *tbl)
{
	t_node	*curr;

	curr = tbl->nodes;
	set_levels(tbl);
	// while (list_len(tbl->unvis))
	// {
	// 	printf("-()_()-");
	// 	calculate_dist(curr, tbl);
	// }
	return (1);
}

void		through_net(t_node *nodder, t_table *tbl, int w, t_node *tail)
{
	t_pipe	*pip;
	t_node	*node;

	printf("hi there\n");
	if (nodder->branch && ft_strcmp(nodder->name, tbl->start->name))
	{
		printf("Not start\n");
		pip = nodder->branch;
		while (pip)
		{
			node = pip->node;
			if (!node->visited)
			{
				printf("---===---\n");
				node->weight = w + 1;
				node->visited = 1;
				printf("END %d", tail->weight);
				through_net(node, tbl, w + 1, tail);
			}
			pip = pip->next;
		}
	}
}

int			set_levels(t_table *tbl)
{
	t_pipe	*pip;
	t_node	*node;
	t_node	*head_node;
	int		w;
	int		count;

	w = 0;
	count = -1;
	head_node = tbl->end;
	head_node->weight = 0;
	head_node->visited = 1;
	if (head_node->branch)
	{
		while (++count < tbl->rooms)
		{
			w++;	
			pip = head_node->branch;
			head_node = pip->node;
			while (pip)
			{
				node = pip->node;
				if (!node->visited)
				{
					node->visited = 1;
					node->weight = w;
				}
				pip = pip->next;
			}
			if (!ft_strcmp(head_node->name, tbl->start->name))	// Fuck i don't know when to stop
				return (1);
		}
		return (0);
		// printf("main END %d", tail->weight);
		// through_net(tail->branch->node, tbl, w, tail);
	}
	else
		return (0);
}