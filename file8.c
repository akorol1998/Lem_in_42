/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 12:30:25 by akorol            #+#    #+#             */
/*   Updated: 2019/06/16 12:30:38 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		forming_queue(t_table *tbl)
{
	int		i;
	int		idx;
	t_node	*cur;

	i = -1;
	while (tbl->q[++i])
		tbl->q[i] = NULL;
	idx = 0;
	tbl->q[idx] = tbl->start;
	cur = tbl->start;
	while (cur && ft_strcmp(cur->name, tbl->end->name))
	{
		queue_up(tbl, cur);
		cur = tbl->q[++idx];
	}
}

void		queue_up(t_table *tbl, t_node *cur)
{
	t_pipe	*pip;
	int		i;
	int		flag;
	int		idx;

	idx = -1;
	pip = cur->branch;
	while (tbl->q[++idx])
		;
	pip = cur->branch;
	while (pip)
	{
		i = -1;
		flag = 1;
		while (tbl->q[++i])
		{
			if (!ft_strcmp(tbl->q[i]->name, pip->node->name))
			{
				if (!ft_strcmp(tbl->end->name, pip->node->name))
					printf("=====Adding previous the end=====\n");
				add_to_prev(tbl, pip->node, cur);
				flag = 0;
			}
		}
		if (flag)
		{
			tbl->q[idx] = pip->node;
			if (!ft_strcmp(tbl->end->name, pip->node->name))
				printf("=====Adding previous the end=====\n");
			add_to_prev(tbl, pip->node, cur);
			idx++;
		}
		pip = pip->next;
	}
}

void		add_to_prev(t_table *tbl, t_node *node, t_node *previous)
{
	t_pipe *prev;

	if (!ft_strcmp(previous->name, tbl->end->name))
		return ;
	prev = node->prev;
	if (!node->prev)
	{
		node->prev = (t_pipe*)malloc(sizeof(t_pipe));
		node->prev->node = previous;
		node->prev->next = NULL;
	}
	else
	{
		while (prev->next)
			prev = prev->next;
		prev->next = (t_pipe*)malloc(sizeof(t_pipe));
		prev->next->node = previous;
		prev->next->next = NULL;
	}
}

void		delete_input_forks(t_table *tbl)
{
	int		i;
	t_node	*node;

	i = 0;
	while (tbl->q[++i])
	{
		node = tbl->q[i];
		if (ft_strcmp(node->name, tbl->end->name) && node->in > 1)
		{
			printf ("ddddddddd %d dddddddd\n", debug(tbl, 1));
			printf ("<<<<<<<<< %d >>>>>>>>\n", tbl->end->in);
			checking_in_forks(node);
		}
	}
}

void		checking_in_forks(t_node *node)
{
	t_pipe	*prev;
	t_node	*p_node;

	prev = node->prev;
	while (prev)
	{
		p_node = prev->node;
		if (p_node->out > 1 && node->in > 1) // needs processing after to delete one link
		{
			delete_fork_func(p_node, node);
			printf("NUMBER OF IN - [%d]\n", node->in);
		}
		prev = prev->next;
	}
	prev = node->prev;
	// while (prev)
	// {
	// 	p_node = prev->node;
	// 	if (node->in > 1)
	// 	{
	// 		delete_fork_func(p_node, node);
	// 		printf("NUMBER OF IN - [%d]\n", node->in);
	// 	}
	// 	prev = prev->next;
	// }
}