/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 12:34:31 by akorol            #+#    #+#             */
/*   Updated: 2019/06/05 12:34:47 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_list(t_table *tbl)
{
	t_node	*n;
	t_node	*start;
	t_node	*end;
	t_pipe	*pip;

	printf(" START %p\n", tbl->start);
	start = tbl->start;
	printf("Address %p\n", start);
	printf("name %s\n", start->name);
	printf("link %p\n", start->link);
	for(int j=0;j<2;j++)
		printf(" pos=%d\n ", start->pos[j]);
	printf("----------------\n\n");

	printf(" END %p\n", tbl->end);
	end = tbl->end;
	printf("Address %p\n", end);
	printf("name %s\n", end->name);
	printf("link %p\n", end->link);
	for(int j=0;j<2;j++)
		printf("pos=%d\n ", end->pos[j]);
	printf("----------------\n\n");
	if (tbl && tbl->nodes)
	{
		n = tbl->nodes;
		printf("Address %p\n", n);
		printf("Ants %d\n", tbl->ants);
		printf("end %s\n", tbl->end->name);
		printf("THE NODE\n");
		while (n)
		{
			if (n->level && n->level != -1)
			{
				printf("---------NODE-------\n\n");
				printf("Address %p\n", n);
				printf("name %s\n", n->name);
				printf("in %d\n", n->in);
				printf("out %d\n", n->out);
				printf("level %d\n", n->level);
				printf("link %p\n", n->link);
				for(int j=0;j<2;j++)
					printf(" pos=%d\n ", n->pos[j]);
				pip = n->branch;
				while (pip)
				{
					printf("---------BRANCH-------\n\n");
					printf("Address %p\n", pip->node);
					printf("name %s\n", pip->node->name);
					printf("link %p\n", pip->node->link);
					for(int j=0;j<2;j++)
						printf(" pos=%d\n ", pip->node->pos[j]);
					printf("                    \n\n");
					printf("                    \n\n");
					pip = pip->next;
				}
			}
			n = n->link;
		}
	}
}