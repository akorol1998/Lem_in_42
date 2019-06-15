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

void		data_tunage(t_table *tbl)
{
	t_pipe	*pip;
	t_node	*node;

	ft_putstr("ewhgjwk\n");
	bad_links(tbl);
	ft_putstr("error\n");
	directions(tbl);
	pip = tbl->start->branch;
	while (pip)
	{
		node = pip->node;
		in_and_out(tbl, node);
		pip = pip->next;
	}
	bad_in_outs(tbl);
	// in_out_to_zero(tbl);
}

void		in_out_to_zero(t_table *tbl)
{
	t_node	*node;
	t_pipe	*pip;

	node = tbl->start;
	while (node)
	{
		pip = node->branch;
		while (pip)
		{
			pip->node->out = 0;
			pip->node->in = 0;
			pip = pip->next;
		}
		node = node->link;
	}
}

void		bad_in_outs(t_table *tbl)
{
	t_pipe	*pip;
	t_node	*node;
	t_pipe	*pre_pip;

	node = tbl->start;
	while (node)
	{
		while (node->branch && (!node->branch->node->out ||
		!node->branch->node->in) &&
		ft_strcmp(node->branch->node->name, tbl->end->name) && 
		ft_strcmp(node->branch->node->name, tbl->start->name))
		{
			ft_putstr("delete ");
			ft_putstr(node->branch->node->name);
			ft_putstr(" \n");
			node->branch = node->branch->next;
		}
		pip = node->branch;
		while (pip)
		{
			if ((!pip->node->out || !pip->node->in) &&
			ft_strcmp(pip->node->name, tbl->end->name) &&
			ft_strcmp(pip->node->name, tbl->start->name))
			{
				ft_putstr("delete ");
				ft_putstr(pip->node->name);
				ft_putstr(" \n");
				pre_pip->next = pip->next;
			}
			else
				pre_pip = pip;
			pip = pip->next;
		}
		node = node->link;
	}
}