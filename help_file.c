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
