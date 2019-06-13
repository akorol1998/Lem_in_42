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
		}
		printf("\n");
	}
	parsing_ants(tbl);
	return (1);
}