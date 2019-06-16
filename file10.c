/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file10.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 16:03:00 by akorol            #+#    #+#             */
/*   Updated: 2019/06/16 16:03:10 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		delete_long_paths(int *arr, t_node *node, int size)
{
	int		a;
	int		i;
	int		idx;

	i = -1;
	a = 999999;
	idx = 999999;
	while (++i < size)
	{
		if (arr[i] < a)
		{
			a = arr[i];
			idx = i;
		}
	}
	// printf("shortest [%d] idx [%d]\n", a, idx);
	delete_links(node, idx);
}

void		delete_links(t_node *node, int idx)
{
	t_pipe	*pip;
	t_pipe	*prepipe;
	int		mydx;

	mydx = 0;
	while (node->branch && mydx != idx)
	{
		// printf("deleting %s [%d]\n", node->branch->node->name, mydx);
		node->branch = node->branch->next;
		mydx++;
	}
	pip = node->branch;
	while (pip)
	{
		if (pip && mydx != idx)
		{
			// printf("deleting %s\n", pip->node->name);
			prepipe->next = pip->next;
		}
		prepipe = pip;
		pip = pip->next;
		mydx++;
	}
}