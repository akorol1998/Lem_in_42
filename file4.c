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