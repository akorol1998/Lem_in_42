/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file9.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 13:21:09 by akorol            #+#    #+#             */
/*   Updated: 2019/06/16 13:21:20 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		delete_output_forks(t_table *tbl)
{
	int		leng;

	leng = 0;
	while (tbl->q[leng])
		leng++;
	while (--leng >= 0)
	{
		if (tbl->q[leng]->out > 1 && ft_strcmp(tbl->q[leng]->name, tbl->start->name))
		{
			printf("name - %d\n", tbl->q[leng]->out);
			int	k = -1;
			while (tbl->q[leng]->vert[++k])
				;
			printf("real out %d\n", k);
			remove_out_links(tbl, tbl->q[leng]);
			exit(1);
			
		}
	}
}

void		remove_out_links(t_table *tbl, t_node *node)
{
	int		size;
	int		*arr;
	int		idx;

	size = -1;
	while (node->vert && node->vert[++size])
		;
	arr = (int*)malloc(sizeof(int) * size);
	idx = 0;
	while (node->vert && node->vert[idx])
	{
		ft_putstr("<< ");
		short_way(arr, node->vert[idx], tbl, idx);
		idx++;
		ft_putstr(" >>\n");
	}
	delete_long_paths(arr, node, size);
	free(arr);
	
	// printf("node is %s [%d]\n", node->name, node->out); //think about it ;)
	// printf("size is %d\n", size);
}

void		refresh_outs(t_table *tbl)
{
	int		j;
	int		k;

	j = -1;
	while (tbl->q[++j])
	{
		k = -1;
		while (tbl->q[j]->vert[++k])
			tbl->q[j]->vert[k]->in++;
		k++;
		tbl->q[j]->out = k;
	}
}

void		short_way(int *arr, t_node *node, t_table *tbl, int idx)
{
	int		count;
	int		i;

	count = 1;
	while (node && ft_strcmp(node->name, tbl->end->name))
	{
		i = -1;
		while (node->vert && node->vert[++i] &&
		node->vert[i]->level < node->level) // Need to go to the room that is lower by level, may be problem with the room of the same level.
			;
		printf("[%s]\n", node->vert[i]->name);
		printf("[%s]\n", node->name);
		node = node->vert[i];
		count++;
	}
	if (!node || ft_strcmp(node->name, tbl->end->name)) // check weather it reaches the end
	{
		printf("Didn't reach the end\n");
		arr[idx] = INT_MAX;
	}
	else
	{
		arr[idx] = count;
	}
	printf("count %d\n", arr[idx]);
}