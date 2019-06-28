/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lems.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 11:51:53 by akorol            #+#    #+#             */
/*   Updated: 2019/06/28 11:52:09 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		swarming(t_table *tbl)
{
	t_node	***path;
	int		ant;
	int		i;
	int		f;
	int		count;

	i = -1;
	ant = 1;
	path = tbl->path;
	f = 1;
	count = 0;
	while (f)
	{
		f = 0;
		while (path && path[++i] && ant <= tbl->ants + 1 &&
		(tbl->ants - ant > make_decision(tbl, i) || tbl->ants == ant))
		{
			move_ants(path[i], ant);
			ant++;
		}
		count += what_to_do(ant, tbl, &i, &f);
	}
	printf("Lines %d\n", count-1);
}

int			cycle_move(t_table *tbl)
{
	int		f;
	int		c;
	int		i;

	f = 1;
	c = 0;
	i = -1;
	while (f)
	{
		f = 0;
		i = -1;
		while (tbl->path[++i])
		{
			if (move_ants(tbl->path[i], -1))
				f = 1;
		}
		c++;
		printf("\n");
	}
	return (c);
}

int			what_to_do(int ant, t_table *tbl, int *i, int *f)
{
	if (tbl->path && !tbl->path[(*i)])
	{
		(*i) = -1;
		(*f) = 1;
		printf("\n");
	}
	else if (ant > tbl->ants)
	{
		if (tbl->path && !tbl->path[(*i)])
			printf("tmp");
		return (cycle_move(tbl));
	}
	else if (tbl->ants - ant <= make_decision(tbl, *i))
	{
		printf("third");
		(*f) = 1;
		(*i) = -1;
	}
	return (1);
}

int			move_ants(t_node **arr, int ant)
{
	int		i;
	int		f;

	i = len_arr(arr, NULL);
	i -= 1;
	f = 0;
	while (--i >= 0 && arr[i])
	{
		if (arr[i]->lem)
			f = 1;
		if (arr[i]->lem)
		{
			arr[i + 1]->lem = arr[i]->lem;
			printf("L%d-%s", arr[i + 1]->lem, arr[i + 1]->name);
		}
		if (!i && ant != -1)
		{
			arr[i]->lem = ant;
			printf("L%d-%s", arr[i]->lem, arr[i]->name);
		}
		else
			arr[i]->lem = 0;
	}
	return (f);
}