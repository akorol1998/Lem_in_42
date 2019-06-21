#include "lem_in.h"

// allocating memmory for 2d array of names of the links
void		save_links(t_table *tbl)
{
	t_node	*node;
	t_pipe	*pip;
	int		counter;

	node = tbl->start;
	while (node)
	{
		pip = node->branch;
		counter = 0;
		while (pip)
		{
			counter++;
			pip = pip->next;
		}
		if (counter)
		{
			node->vert = (t_node**)malloc(sizeof(t_node*) * counter + 1);
			node->vert[counter] = NULL;
			pip = node->branch;
			while (counter--)
			{
				node->vert[counter] = pip->node;
				pip = pip->next;
			}
		}
		node = node->link;
	}
}

void		clean_branch(t_pipe *pip)
{
	if (pip->next)
	{
		clean_branch(pip->next);
		free(pip->next);
	}
}

void		add_branches(t_table *tbl)
{
	t_node	*node;
	t_pipe	*pip;
	int		i;

	node = tbl->start;
	while (node)
	{
		if (node->branch)
		{
			clean_branch(node->branch);
			free(node->branch);
		}
		i = 0;
		if (node->vert)
		{
			node->branch = (t_pipe*)malloc(sizeof(t_pipe));
			node->branch->node = node->vert[0];
			pip = node->branch;
			while (node->vert[++i])
			{
				pip->next = (t_pipe*)malloc(sizeof(t_pipe));
				pip->next->node = node->vert[i];
				pip = pip->next;
			}
			pip->next = NULL;
		}
		if (node->prev)
		{
			clean_branch(node->prev);
			free(node->prev);
		}
		node->prev = NULL;
		node->level = -1;
		node = node->link;
	}
}