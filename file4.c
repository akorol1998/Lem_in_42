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
	size = 1;
	while (ft_strcmp(node->name, tbl->start->name))
	{
		node = node->prev;
		size++;
	}
	return (size);
}

int			finish_ants(t_node **node, int ants)
{
	int		i;
	int		buf;
	int		flag;

	i = 0;
	buf = -1;
	flag = 0;
	while(node[++i])
	{
		if (node[i]->lem)
		{
			buf = node[i]->lem;
			node[i]->lem = ants;
			ants = buf;
			flag = 1;
			if (node[i + 1])
				printf("L%d->%s ", ants, node[i + 1]->name);
		}
	}
	return (flag);
}

int			move_lems(t_node **node, int ants)
{
	int		i;
	int		buf;
	int		flag;

	i = 0;
	buf = -1;
	flag = 0;
	if (!ants)
		return (finish_ants(node, ants));
	while(node[++i])
	{
		if (node[i]->lem || buf == ants)
		{
			buf = node[i]->lem;
			node[i]->lem = ants;
			ants = buf;
			if (node[i]->lem)
				printf("L%d->%s ", node[i]->lem, node[i]->name);
			flag = 1;
			// if (node[i + 1]) Case of another function
			// 	printf("L%d->%s ", ants, node[i + 1]->name);
		}
		else if (i == 1)
		{
			if (node[i]->lem)
				buf = node[i]->lem;
			node[i]->lem = ants;
			if (node[i]->lem)
				printf("L%d->%s ", node[i]->lem, node[i]->name);
			flag = 1;
		}
	}
	return (flag);
}

void		parsing_ants(t_table *tbl)
{
	int		i;
	int		ants;
	int		move;
	int		flag;

	ants = 1;
	move = len_arr(tbl->path[0], NULL) + ants - 2;
	printf("ants number %d\n", tbl->ants);
	while (ants <= tbl->ants)
	{
		i = -1;
		while (ants <= tbl->ants && tbl->path[++i])
		{
			if ((len_arr(tbl->path[i], NULL) + ants - 2) - move < ants)
				move_lems(tbl->path[i], ants);
			else
			{
				i = 0;
				move_lems(tbl->path[i], ants);
			}
			ants++;
		}
		printf("\n");
		if (ants == tbl->ants)
		{
			flag = 1;
			while (flag)
			{
				flag = 0;
				i = -1;
				while (tbl->path[++i])
				{
					if (move_lems(tbl->path[i], 0))
						flag = 1;
				}
				printf("\n");
			}
		}
			//moving lems
	}
}

int			display_ants(t_table *tbl)
{
	int		i;
	int		j;

	i =	-1;
	// printf(" length %d\n", len_arr(NULL, tbl->path));
	// sort_arr(tbl);
	while (tbl->path[++i])
	{
		j = -1;
		printf("path is: ");
		while (tbl->path[i][++j])
		{
			printf("[%s] ", tbl->path[i][j]->name);
		}
		printf("\n");
	}
	parsing_ants(tbl);
	return (1);
}

int			len_arr(t_node **nodes, t_node ***arr)
{
	int		i;

	if (!arr)
	{
		i = -1;
		while (nodes[++i])
			;
	}
	else
	{
		i = -1;
		while (arr[++i])
			;
	}
	return (i);
}

// void		sort_arr(t_table *tbl)
// {
// 	t_node	**least;
// 	int		flag;
// 	int		leng;
// 	int		i;

// 	flag = 1;
// 	leng = len_arr(NULL, tbl->path);
// 	if (tbl->path)
// 		least = tbl->path[0];
// 	while (flag)
// 	{
// 		flag = 0;
// 		i = -1;
// 		while (++i < leng)
// 		{
// 			if (tbl->path[i + 1] && len_arr(tbl->path[i], NULL) >
// 			len_arr(tbl->path[i + 1], NULL))
// 			{
// 				least = tbl->path[i + 1];
// 				tbl->path[i + 1] = tbl->path[i];
// 				tbl->path[i] = least;
// 				flag = 1;
// 			}
// 		}
// 	}
// }
