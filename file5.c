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
		while (nodes[++i])
			;
	else
		while (arr[++i])
			;
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
		ft_printf("path is: ");
		while (tbl->path[i][++j])
		{
			ft_printf("[%s] ", tbl->path[i][j]->name);
		}
		ft_printf("\n");
	}
	swarming(tbl);
	return (1);
}

void		finish_rest(t_table *tbl, int i)
{
	t_node	**path;
	int		leng;
	
	while (tbl->path[i])
	{
		path = tbl->path[i];
		leng = len_arr(path, NULL);
		leng--;
		while (leng-- && path[leng])
		{
			if (path[leng]->lem)
			{
				path[leng + 1]->lem = path[leng]->lem;
				ft_printf(" L%d-%s", path[leng + 1]->lem, path[leng + 1]->name);
			}
			path[leng]->lem = 0;
		}
		i++;
	}
}