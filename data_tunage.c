/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 16:43:23 by akorol            #+#    #+#             */
/*   Updated: 2019/06/15 16:43:34 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		clean_in_out(t_table *tbl)
{
	int		sign;

	sign = 1;
	while (sign)
	{
		sign = 0;
		in_out_to_zero(tbl);
		in_and_out(tbl);
		sign = bad_in_outs(tbl, sign);
	}
}

void		data_tunage(t_table *tbl)
{
	int		c;
	int		sign;

	sign = 1;
	c = 0;
	
	bad_links(tbl);
	directions(tbl);
	clean_in_out(tbl);
	forming_queue(tbl);
	clean_in_out(tbl);
	delete_input_forks(tbl);
	clean_in_out(tbl);
	delete_output_forks(tbl);
	clean_in_out(tbl);
}

void		in_out_to_zero(t_table *tbl)
{
	int		i;

	i = -1;
	while (tbl->q[++i])
	{
		tbl->q[i]->out = 0;
		tbl->q[i]->in = 0;
	}
}

void		in_and_out(t_table *tbl)
{
	int		i;
	int		j;

	i = -1;
	while (tbl->q[++i])
	{
		j = -1;
		while (tbl->q[i]->vert && tbl->q[i]->vert[++j])
		{
			tbl->q[i]->out++;
			tbl->q[i]->vert[j]->in++;
		}
	}
}

// Deleting dead ends
int			bad_in_outs(t_table *tbl, int sign)
{
	t_node	*node;
	int		i;
	int		j;

	i = -1;
	while (tbl->q[++i])
	{
		node = tbl->q[i];
		
		j = -1;
		while (node->vert && node->vert[++j])
		{
			if ((!node->vert[j]->out || !node->vert[j]->in) &&
			ft_strcmp(node->vert[j]->name, tbl->end->name) && 
			ft_strcmp(node->vert[j]->name, tbl->start->name))
			{
				delete_from_vert(node, j);
				j--;
				sign = 1;
			}
		}
	}
	return (sign);
}