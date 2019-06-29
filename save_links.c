/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 16:18:16 by akorol            #+#    #+#             */
/*   Updated: 2019/06/29 16:18:17 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// allocating memmory for 2d array of names of the links
void		save_links(t_table *tbl)
{
	t_node	*node;
	t_pipe	*pip;
	int		counter;

	node = tbl->start;
	while (node)
	{
		pip = node->branch;
		counter = 0;
		while (pip)
		{
			counter++;
			pip = pip->next;
		}
		if (counter)
		{
			node->vert = (t_node**)malloc(sizeof(t_node*) * counter + 1);
			node->vert[counter] = NULL;
			pip = node->branch;
			while (counter--)
			{
				node->vert[counter] = pip->node;
				pip = pip->next;
			}
		}
		node = node->link;
	}
}

void		clean_branch(t_pipe *pip)
{
	if (pip->next)
	{
		clean_branch(pip->next);
		free(pip->next);
		pip->next = NULL;
	}
}

void		add_branches(t_table *tbl)
{
	t_node	*node;
	int		i;

	node = tbl->start;
	
	while(node)
	{
		if (node->vert)
			free(node->vert);
		if (node->pre_arr)
			free(node->pre_arr);
		node->level = -1;
		node->pre_arr = NULL;
		node->vert = NULL;
		node->out = 0;
		node->in = 0;
		node = node->link;
	}
	i = -1;
	while (tbl->q[++i])
		tbl->q[i] = NULL;
}
