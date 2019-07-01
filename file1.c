/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 15:05:40 by akorol            #+#    #+#             */
/*   Updated: 2019/06/04 15:05:42 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			start_end(char **data, t_node *node)
{
	int		i;

	i = -1;
	node->name = ft_strdup(data[0]);
	node->pos = (int *)malloc(sizeof(int) * 2);
	node->pos[0] = ft_atoi(data[1]);
	node->pos[1] = ft_atoi(data[2]);
	while (data && data[++i])
		free(data[i]);
	free(data);
	return (1);
}

int			start_end_node(char c, char **data, t_node *node, t_table *tbl)
{
	if (c == 'e' && !tbl->end)
	{
		tbl->end = node;
		node = tbl->nodes;
		while (node->link)
			node = node->link;
		node->link = tbl->end;
		node = tbl->end;
	}
	else if (c == 's' && !tbl->start)
	{
		tbl->start = node;
		if (tbl->nodes)
		{
			node->link = tbl->nodes;
			tbl->nodes = node;
		}
		else
			tbl->nodes = node;
	}
	else if (tbl->end || tbl->start)
		return (0);
	return (start_end(data, node));
}

void		valid_line(t_table *tbl, char *line, char c, int *r)
{
	t_node	*node;
	char	**data;

	data = ft_strsplit(line, ' ');
	if (check_room(data, tbl))
	{
		node = create_node();
		if (!((*r) = start_end_node(c, data, node, tbl)))
		{
			(*r) = -1;
			while (data && data[++(*r)])
				free(data[*r]);
			free(data);
			(*r) = 0;
			recursive_node(tbl, node);
			free(node);
		}
		tbl->rooms++;
	}
	free(line);
}

int			read_line(t_table *tbl, char c)
{
	char	*line;
	int		r;

	r = 0;
	while (1)
	{
		get_next_line(0, &line);
		join_map(tbl, line);
		if (line && line[0] == '#')
		{
			if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
			{
				ft_printf("Don't know how to process this!\n");
				free(line);
				return (0);
			}
			free(line);
		}
		else
		{
			valid_line(tbl, line, c, &r);
			break ;
		}
	}
	return (r);
}

int			reading_links(char *line0, t_table *tbl)
{
	char	*line;
	char	**data;
	int		res;

	line = NULL;
	data = ft_strsplit(line0, '-');
	if (!(res = check_for_links(data, tbl)))
	{
		return (0);
	}
	while (get_next_line(0, &line))
	{
		join_map(tbl, line);
		data = ft_strsplit(line, '-');
		if (!(res = check_for_links(data, tbl)))
		{
			free(line);
			return (0);
		}
		free(line);
	}
	return (1);
}
