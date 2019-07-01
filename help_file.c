/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:40:21 by akorol            #+#    #+#             */
/*   Updated: 2019/06/30 12:41:08 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


int			ant_check(char	*line)
{
	int		i;

	i = -1;
	while (line[++i])
	{
		if (!ft_isdigit(line[i]))
			return (0);
	}
	return (1);
}

void		join_map(t_table *tbl, char *line)
{
	char	*del;

	if (!tbl->map)
	{
		tbl->map = ft_strdup(line);
		del = tbl->map;
		tbl->map = ft_strjoin(tbl->map, "\n");
		free(del);
	}
	else
	{
		del = tbl->map;
		tbl->map = ft_strjoin(tbl->map, line);
		free(del);
		del = tbl->map;
		tbl->map = ft_strjoin(tbl->map, "\n");
		free(del);
	}
}

int				check_line(char *line, t_table *tbl)
{
	if (!ft_strcmp(line, "##start"))
	{
		if (!read_line(tbl, 's'))
			return (0);
	}
	else if (!ft_strcmp(line, "##end"))
	{
		if (!read_line(tbl, 'e'))
			return (0);
	}
	else if (line[0] == '#')
		return (1);
	else
		return (check_valid_line(line, tbl));
	return (1);
}

int			check_valid_line(char *line, t_table *tbl)
{
	char	**data;
	t_node	*node;

	data = ft_strsplit(line, ' ');
	if (check_room(data, tbl))
	{
		node = create_node();
		fill_node(data, node, tbl);
		return (1);
	}
	return (0);
}

int			count_nodes(t_table *tbl, int idx)
{
	t_node	*node;
	int		size;

	node = tbl->q[idx];
	size = 0;
	while (ft_strcmp(node->name, tbl->start->name))
	{
		node = node->prev;
		size++;
	}
	return (size);
}
