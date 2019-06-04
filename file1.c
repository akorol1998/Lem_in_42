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

int			read_start(t_table *tbl)
{
	char	*line;
	char	**data;
	t_node	*node;

	get_next_line(0, &line);
	data = ft_strsplit(line, ' ');
	node = create_node();
	if (check_room(data))
	{
		node = create_node();
		fill_node(data, node, tbl);
		return (1);
	}
	free(line);
	return (0);
}