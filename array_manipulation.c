/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_manupulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 10:14:03 by akorol            #+#    #+#             */
/*   Updated: 2019/06/24 10:14:17 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		delete_from_vert(t_node *node, int idx)
{
	int		leng;

	leng = -1;
	while (node->vert[++leng])
		;
	node->vert[idx] = NULL;
	if (idx != leng - 1)
	{
		while (node->vert[++idx])
		{
			node->vert[idx - 1] = node->vert[idx];
			node->vert[idx] = NULL;
		}
	}
}

void		prev_to_arr(t_table *tbl)
{
	t_node	*node;
	t_pipe	*pip;
	int		i;
	int		j;

	i = -1;
	while (tbl->q[++i])
	{
		node = tbl->q[i];
		j = 0;
		pip = node->prev;
		while (pip)
		{
			j++;
			pip = pip->next;
		}
		if (j)
		{
			node->pre_arr = (t_node**)malloc(sizeof(t_node) * j + 1);
			node->pre_arr[j] = NULL;
			pip = node->prev;
			while (j--)
			{
				node->pre_arr[j] = pip->node;
				pip = pip->next;
			}
		}
	}
	// printf("Total is [%s]\n", tbl->q[i-1]->name);
}

void		free_prev_links(t_table *tbl)
{
	t_node	*node;
	int		i;

	i = -1;
	while (tbl->q[++i])
	{
		node = tbl->q[i];
		if (node->prev)
		{
			clean_branch(node->prev);
			free(node->prev);
			node->prev = NULL;
		}	
	}
}