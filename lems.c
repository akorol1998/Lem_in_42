/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lems.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 08:53:45 by akorol            #+#    #+#             */
/*   Updated: 2019/06/30 08:53:51 by akorol           ###   ########.fr       */
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
	ant = 0;
	path = tbl->path;
	f = 1;
	count = 0;
	ft_putstr("NUMBER OF ANTS IS           ");
	ft_putnbr(tbl->ants);
	ft_putstr("\n");
	while (f)
	{
		f = 0;
		while (path && path[++i] && ant < tbl->ants &&
		(tbl->ants - ant > make_decision(tbl, i) || tbl->ants == ant))
			move_ants(path[i], &ant);
		if ((path[i] && tbl->ants - ant < make_decision(tbl, i)) || ant == tbl->ants)
			finish_rest(tbl, i);
		ft_printf("\n");
		count += what_to_do(ant, tbl, &i, &f);
	}
	ft_putstr("Lines ");
	ft_putnbr(count);
	ft_putstr("\n");
}

int			cycle_move(t_table *tbl)
{
	int		f;
	int		c;
	int		i;
	int		a;

	f = 1;
	c = 0;
	i = -1;
	while (f)
	{
		f = 0;
		i = -1;
		while (tbl->path[++i])
		{
			a = -1;
			if (move_ants(tbl->path[i], &a))
				f = 1;
		}
		c++;
		ft_putstr("\n");
	}
	return (c);
}

int			what_to_do(int ant, t_table *tbl, int *i, int *f)
{
	if (tbl->path && !tbl->path[(*i)])
	{
		(*i) = -1;
		(*f) = 1;
	}
	if (ant == tbl->ants)
	{
		(*f) = 0;
		return (cycle_move(tbl));
	}
	if (tbl->path[*i] && (*i) != -1 && tbl->ants - ant <= make_decision(tbl, (*i)))
	{
		(*f) = 1;
		(*i) = -1;
	}
	return (1);
}

int			move_ants(t_node **arr, int *ant)
{
	int		i;
	int		f;

	i = len_arr(arr, NULL);
	i -= 1;
	f = 0;
	(*ant) = (*ant) == -1 ? -1 : (*ant) + 1;
	if (!i && (*ant) != -1)
		ft_printf("L%d-%s ", (*ant), arr[i]->name);
	while (--i >= 0 && arr[i])
	{
		if (arr[i]->lem)
		{
			f = 1;
			arr[i + 1]->lem = arr[i]->lem;
			ft_printf("L%d-%s ", arr[i + 1]->lem, arr[i + 1]->name);
		}
		if (!i && (*ant) != -1)
		{
			arr[i]->lem = (*ant);
			ft_printf("L%d-%s ", arr[i]->lem, arr[i]->name);
		}
		else
			arr[i]->lem = 0;
	}
	return (f);
}

int			make_decision(t_table *tbl, int idx)
{
	int		leng;
	int		sum;
	int		i;
	
	leng = len_arr(tbl->path[idx], NULL);
	sum = 0;
	i = -1;
	while (++i < idx)
		sum += (leng - len_arr(tbl->path[i], NULL));
	return (sum);
}
