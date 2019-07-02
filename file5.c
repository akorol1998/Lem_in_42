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

	i = -1;
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
				ft_printf("L%d-%s ", path[leng + 1]->lem, path[leng + 1]->name);
			}
			path[leng]->lem = 0;
		}
		i++;
	}
}

int			room_in_path(t_table *tbl)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (tbl->path[++i])
	{
		j = -1;
		while (tbl->path[i][++j])
			;
		if (j == 1 && !ft_strcmp(tbl->path[i][0]->name, tbl->end->name))
			return (1);
	}
	return (0);
}

void		really_add(t_node *cur, t_pipe *pip, t_table *tbl, int *idx)
{
	int		i;
	int		flag;

	i = -1;
	flag = 1;
	while (tbl->q[++i])
	{
		if (pip->node->visited ||
		!ft_strcmp(tbl->q[i]->name, pip->node->name))
			flag = 0;
	}
	if (flag)
	{
		if (ft_strcmp(cur->name, tbl->start->name) ||
		ft_strcmp(pip->node->name, tbl->end->name) || !room_in_path(tbl))
		{
			tbl->q[(*idx)] = pip->node;
			pip->node->prev = cur;
			(*idx)++;
		}
	}
}
