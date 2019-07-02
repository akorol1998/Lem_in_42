/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 00:11:31 by akorol            #+#    #+#             */
/*   Updated: 2019/06/13 00:11:46 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		recursive_pip(t_pipe *pip)
{
	if (pip && pip->next)
	{
		recursive_pip(pip->next);
		free(pip->next);
	}
}

void		recursive_node(t_table *tbl, t_node *node)
{
	if (node && node->link)
	{
		recursive_node(tbl, node->link);
		free(node->link);
		node->link = NULL;
	}
	if (node && node->branch)
	{
		recursive_pip(node->branch);
		free(node->branch);
		node->branch = NULL;
	}
	if (node && node->name)
	{
		free(node->name);
		node->name = NULL;
	}
	if (node && node->pos)
	{
		free(node->pos);
		node->pos = NULL;
	}
}

void		clean_function(t_table *tbl)
{
	int		i;

	if (tbl->q)
		free(tbl->q);
	tbl->q = NULL;
	i = -1;
	while (tbl->path && tbl->path[++i])
		free(tbl->path[i]);
	if (tbl->path)
		free(tbl->path);
	tbl->path = NULL;
	if (tbl->msg)
		free(tbl->msg);
	tbl->msg = NULL;
	if (tbl->map)
		free(tbl->map);
	tbl->map = NULL;
	recursive_node(tbl, tbl->nodes);
}

int			arr_and_algo(t_table *tbl)
{
	int		flag;

	flag = 0;
	creating_arrays(tbl);
	ft_printf("%s\n", tbl->map);
	flag = launch_algorithm(tbl);
	if (flag)
	{
		display_ants(tbl);
		if (tbl->msg)
			ft_printf("%s\n", tbl->msg);
		return (1);
	}
	else
	{
		clean_function(tbl);
		ft_printf("%s\n", strerror(EIO));
		return (0);
	}
}

int			start_reading(t_table *tbl)
{
	char	*line;

	if (!get_ants(tbl))
	{
		clean_function(tbl);
		return (0);
	}
	if ((line = reading_rooms(tbl)) && tbl->start && tbl->end)
	{
		if (!reading_links(line, tbl))
		{
			ft_printf("Invalid links!\n");
			free(line);
			clean_function(tbl);
			return (0);
		}
		free(line);
		return (arr_and_algo(tbl));
	}
	else
	{
		ft_printf("%s\n", strerror(EIO));
		clean_function(tbl);
		return (0);
	}
}
