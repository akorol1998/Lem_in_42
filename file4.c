/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 00:11:31 by akorol            #+#    #+#             */
/*   Updated: 2019/06/13 00:11:46 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			count_nodes(t_table *tbl, int idx)
{
	t_node	*node;
	int		size;

	node = tbl->q[idx];
	size = 0;
	while (ft_strcmp(node->name, tbl->start->name))
	{
		node = node->prev;
		size++;
	}
	return (size);
}

void		recursive_pip(t_pipe *pip)
{
	if (pip->next)
	{
		recursive_pip(pip->next);
		free(pip->next);
	}
}

void		recursive_node(t_table *tbl, t_node *node)
{
	if (node && node->link)
	{
		recursive_node(tbl, node->link);
		free(node->link);
	}
	if (node && node->branch)
	{
		recursive_pip(node->branch);
		free(node->branch);
	}
	if (node && node->name)
		free(node->name);
	if (node && node->pos)
		free(node->pos);
}

void		clean_function(t_table *tbl)
{
	int		i;

	if (tbl->q)
		free(tbl->q);
	i = -1;
	while (tbl->path && tbl->path[++i])
		free(tbl->path[i]);
	if (tbl->path)
		free(tbl->path);
	if (tbl->msg)
		free(tbl->msg);
	if (tbl->map)
		free(tbl->map);
	recursive_node(tbl, tbl->nodes);
}