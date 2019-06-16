/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 19:29:51 by akorol            #+#    #+#             */
/*   Updated: 2019/06/13 19:30:01 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			len_arr(t_node **nodes, t_node ***arr)
{
	int		i;

	i = -1;
	if (!arr)
	{	
		while (nodes[++i])
			;
	}
	else
	{
		while (arr[++i])
			;
	}
	return (i);
}

int			display_ants(t_table *tbl)
{
	int		i;
	int		j;

	i =	-1;
	while (tbl->path[++i])
	{
		j = -1;
		printf("path is: ");
		while (tbl->path[i][++j])
		{
			printf("[%s] ", tbl->path[i][j]->name);
			printf("[%d] ", tbl->path[i][j]->level);
		}
		printf("\n");
	}
	// parsing_ants(tbl);
	return (1);
}

int			finish_rest(t_table *tbl, int idx)
{
	t_node	**node;
	int		i;
	int		ants;
	int		buf;

	ants = 0;
	buf = -1;
	while (tbl->path[idx])
	{
		node = tbl->path[idx];
		i = -1;
		while(node[++i])
		{
			if (node[i]->lem || buf == ants)
			{
				buf = node[i]->lem;
				node[i]->lem = ants;
				ants = buf;
				if (node[i]->lem)
					printf("L%d->%s ", node[i]->lem, node[i]->name);
			}
		}
		idx++;
	}
	return (1);
}