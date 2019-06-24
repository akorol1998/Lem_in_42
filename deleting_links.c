/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 11:43:31 by akorol            #+#    #+#             */
/*   Updated: 2019/06/15 11:43:43 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


void		count_pip(t_table *tbl, t_node *node)
{
	t_pipe	*pip;
	t_node	*r;

	pip = node->branch;
	while (pip)
	{
		printf("Node [%s] in[%d] out[%d] link -> [%s]\n", node->name, node->in, node->out, pip->node->name);
		printf("Node level [%d] linked level -> [%d]\n", node->level, pip->node->level);
		pip = pip->next;
	}
	printf("\n");
	r = tbl->start;
}

int			setting_levels(t_table *tbl, t_node *cur)
{
	int		idx;
	int		flag;

	idx = 0;
	tbl->q[idx] = cur;
	flag = 0;
	while (cur && ft_strcmp(cur->name, tbl->end->name))
	{
		add_to_queue(tbl, cur);
		cur = tbl->q[++idx];
	}
	printf("Boy [%d]\n", idx);
	if (cur && !ft_strcmp(cur->name, tbl->end->name))
		flag = 1;
	tbl->end->level = INT_MAX;
	if (!flag)
		return (-1);
	return (idx);
}

// Setting up directions for the nodes
void		set_direction(t_node *part, t_node *root)
{
	// t_pipe	*pip;
	// t_node	*node;
	// t_pipe	*del;
	// t_pipe	*pre_pip;
	int		k;

	k = -1;
	while (part->vert && part->vert[++k])
	{
		if (!ft_strcmp(part->vert[k]->name, root->name) && root->level < part->level)
			delete_from_vert(part, k);
	}
	// pip = node->branch;
	// while (pip)
	// {
	// 	if (!ft_strcmp(pip->node->name, root->name) &&
	// 	root->level < node->level) // || (pip->node->level == -1)
	// 	{
	// 		del = pre_pip->next;
	// 		pre_pip->next = pip->next;
	// 		free(del);
	// 	}
	// 	else
	// 		pre_pip = pip;
	// 	pip = pip->next;
	// }
	// node = tbl->start;
}

void		directions(t_table *tbl)
{
	int		i;
	int		j;

	i = -1;
	while (tbl->q[++i])
	{
		j = -1;
		while (tbl->q[i]->vert[++j])
			set_direction(tbl->q[i]->vert[j], tbl->q[i]);
	}
}

// Deleting same levele links and levele = -1
void		bad_links(t_table *tbl)
{
	// t_pipe	*pip;
	// t_pipe	*del;
	t_node	*node;
	// t_pipe	*pre_pip;
	int		i;
	int		j;

	i = -1;
	g_node = NULL;
	while (tbl->q[++i])
	{
		node = tbl->q[i];
		// if (!ft_strcmp(node->name, tbl->end->name))
		// {
		// 	printf("End {%s}, in-[%d] out-[%d]\n", tbl->q[i]->name, tbl->q[i]->in, tbl->q[i]->out);
		// 	printf("Level of the END [%d]\n", tbl->end->level);
		// }
		// if (!ft_strcmp(node->name, "Uhr4"))
		// {
		// 	g_node = node;
		//	count_pip(tbl, g_node);
		// 	printf("Node {%s}, in-[%d] out-[%d]\n", tbl->q[i]->name, tbl->q[i]->in, tbl->q[i]->out);
		// 	printf("Node level [%d]\n", tbl->q[i]->level);
		// }
		j = -1;
		printf("Sup man\n");
		if (!ft_strcmp("Kys5", node->name)) //Debug this
		{
			for(int k = 0;node->vert[k];k++)
				printf("node [%s]", node->vert[k]->name);
		}
		while (node->vert && node->vert[++j])
		{
			if (node->vert[j]->level == node->level || node->vert[j]->level == -1)
			{
				delete_from_vert(node, j);
				j--; // Play with this boys :)
			}

		}
		printf("\n");
		if (!ft_strcmp("Kys5", node->name)) //Debug this
		{
			for(int k = 0;node->vert[k];k++)
				printf("node [%s]", node->vert[k]->name);
		}
		// pip = node->branch;
		// while (pip)
		// {
			
		// 	if (pip->node->level == node->level || pip->node->level == -1)
		// 	{
		// 		del = pre_pip->next;
		// 		pre_pip->next = pip->next;
		// 		free(del);
		// 	}
		// 	else
		// 		pre_pip = pip;
		// 	pip = pip->next;
		// }
		// if (g_node)
		// {
		// 	printf("<< ");
		// 	count_pip(tbl, g_node);
		// 	printf(" >>\n");
		// }
	}
}