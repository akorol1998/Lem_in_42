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

// int			count_nodes(t_table *tbl, int idx)
// {
// 	t_node	*node;
// 	int		size;

// 	node = tbl->q[idx];
// 	size = 1;
// 	while (ft_strcmp(node->name, tbl->start->name))
// 	{
// 		node = node->prev;
// 		size++;
// 	}
// 	return (size);
// }

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
		if (node[i]->lem || buf == ants)
		{
			buf = node[i]->lem;
			node[i]->lem = ants;
			ants = buf;
			flag = 1;
			if (node[i]->lem)
				printf("L%d->%s ", node[i]->lem, node[i]->name);
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
		if (node[i]->lem || buf == ants || i == 1)
		{
			buf = node[i]->lem;
			node[i]->lem = ants;
			ants = buf;
			if (node[i]->lem)
			{
				flag = 1;
				printf("L%d->%s ", node[i]->lem, node[i]->name);
			}
		}
		// else if (i == 1)
		// {
		// 	// if (node[i]->lem)
		// 	buf = node[i]->lem;
		// 	node[i]->lem = ants; // Possibly need to add line with ants = buf;
		// 	ants = buf;
		// 	if (node[i]->lem)
		// 		printf("L%d->%s ", node[i]->lem, node[i]->name);
		// 	flag = 1;
		// }
	}
	return (flag);
}

int		end_part_of_parsing(t_table *tbl, int count)
{
	int 	flag;
	int		i;

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
		count++;
		printf("\n");
	}
	printf("number of lines [%d]\n", count);
	return (1);
}

int			parsing_ants(t_table *tbl)
{
	int		i;
	int		ants;
	int		count;

	ants = 1;
	count = 0;
	printf("NUMBER OF ANTS IS           %D\n", tbl->ants);
	if (!tbl->path[0])
		return (0);
	while (ants <= tbl->ants)
	{
		i = -1;
		while (ants <= tbl->ants && tbl->path[++i])
		{
			if (((len_arr(tbl->path[i], NULL) + (tbl->ants - ants) - 2) -
			(len_arr(tbl->path[0], NULL) + (tbl->ants - ants) - 2)) < (tbl->ants - ants))
			{
				move_lems(tbl->path[i], ants);
			}
			else
			{
				finish_rest(tbl, i);
				// printf("break = ");
				printf("\n");
				i = 0;
				move_lems(tbl->path[i], ants);
				// count++;
			}
			ants++;
			// printf(" = counted");
		}
		if (tbl->path[++i])
			return (end_part_of_parsing(tbl, count));
		count++;
		printf("\n");
	}
	return (end_part_of_parsing(tbl, count));
}