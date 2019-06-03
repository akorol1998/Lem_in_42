/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 16:08:15 by akorol            #+#    #+#             */
/*   Updated: 2019/06/03 16:08:17 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_table		*create_table()
{
	t_table	*point;

	point = (t_table*)malloc(sizeof(t_table));
	point->prev = NULL;
	point->way = NULL;
	point->prev = NULL;
	point->nodes = NULL;
	point->vis = NULL;
	point->unvis = NULL;
	point->ants = 0;
	return (point);
}

t_node		*create_node()
{
	t_node	*node;

	node = (t_node*)malloc(sizeof(t_node));
	node->weight = 99999;
	node->current = 1;
	node->pos = NULL;
	node->branch = NULL;
	node->name = NULL;
}

int			fill_node(char **data, t_node *node, t_table *tbl)
{
	tbl->nodes = node;
	node->name = data[0];
	node->pos = (int*)malloc(sizeof(int) * 2);
	node->pos[0] = data[1];
	node->pos[0] = data[2];
}