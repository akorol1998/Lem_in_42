/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 16:08:15 by akorol            #+#    #+#             */
/*   Updated: 2019/06/03 16:08:17 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_table		*create_table()
{
	t_table	*point;

	point = (t_table*)malloc(sizeof(t_table));
	point->q = NULL;
	point->nodes = NULL;
	point->start = NULL;
	point->end = NULL;
	point->ants = 0;
	point->rooms = 0;
	return (point);
}

t_node		*create_node(void)
{
	t_node	*node;


	node = (t_node*)malloc(sizeof(t_node));
	node->level = -1;
	node->lem = 0;
	node->out = 0;
	node->in = 0;
	node->pos = NULL;
	node->link = NULL;
	node->branch = NULL;
	node->name = NULL;
	node->visited = 0;
	node->branch = NULL;
	node->prev = NULL;
	return (node);
}

// This fucntion frees "data array" !
int			fill_node(char **data, t_node *node, t_table *tbl)
{
	t_node	*tbl_node;
	int		i;

	i = -1;
	tbl_node = tbl->nodes;
	while (tbl_node && tbl_node->link != NULL)
		tbl_node = tbl_node->link;
	if (!tbl_node)
		tbl->nodes = node;
	else
		tbl_node->link = node;
	node->name = ft_strdup(data[0]);
	node->pos = (int *)malloc(sizeof(int) * 2);
	node->pos[0] = ft_atoi(data[1]);
	node->pos[1] = ft_atoi(data[2]);
	tbl->rooms++;
	while (data && data[++i])
		free(data[i]);
	free(data);
	return (1);
}

// This function usually frees "data array" !
int			check_for_links(char **data, t_table *tbl)
{
	int		i;
	int		k;
	static int	c;

	c++;
	i = -1;
	while (data && data[++i])
			;
	if (i != 2)
	{
		i = -1;
		while (data && data[++i])
			free(data[i]);
		free(data);
		printf("here zero");
		return (0);
	}
	k = linking(data, tbl);
	// t_pipe	*tub;
	// t_node	*node;

	// node = tbl->end;
	// tub = node->branch;
	// if (tub)
	// {
	// 	ft_putstr(node->name);
	// 	ft_putstr("\n");
	// 	tub = tub->next;
	// }
	i = -1;
	while (data && data[++i])
		free(data[i]);
	free(data);
	return (k);
}
