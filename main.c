/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 13:03:19 by akorol            #+#    #+#             */
/*   Updated: 2019/06/03 13:03:20 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			get_ants(t_table *tbl)
{
	int		ants;
	char	*line;

	ants = 0;
	line = NULL;
	while (1)
	{
		get_next_line(0, &line);
		if (ant_check(line))
		{
			ants = ft_atoi(line);
			printf("foo\n");
			break ;
		}
		printf("goo\n");
		free(line);
	}
	if (ants < 0 || !ants)
		return (0);
	else
		free(line);
	tbl->ants = ants;
	return (1);
}

int			check_num(char **data)
{
	int		i;
	int		k;

	i = 0;
	while (data[++i])
	{
		k = -1;
		while (data[i][++k])
		{
			if (!ft_isdigit(data[i][k]))
				return (0);
		}
	}
	return (1);
}

int			check_room(char **data)
{
	int		k;

	k = -1;
	while (data[++k])
			;
	if (k != 3)
	{
		// while (data && data[++k])
		// {
		// 	free(data[k]);
		// 	free(data);
		// }
		return (0);
	}
	else if (!check_num(data))
		return (0);
	printf("Yep here is a room [%s]\n", data[0]);
	return (1);
}

int			reading_rooms(t_table *tbl)
{
	char	*line;
	char	**data;
	int		flag;
	t_node	*node;

	flag = 1;
	line = NULL;
	while (flag)
	{
		get_next_line(0, &line);
		data = ft_strsplit(line, ' ');
		if (check_room(data))
		{
			node = create_node();
			fill_node(data, node, tbl);
		}
		if (!ft_strcmp(line, "##start"))
		{
			if (!read_start(tbl))
				return (0);
		}
		printf("privet\n");
		// free(line); What da fuck??
	}
	return (1);
}

int			start_reading(void)
{
	t_table	*table;
	int		ants;

	table = create_table();
	ants = get_ants(table);
	reading_rooms(table);
	printf("Your ants %d\n", table->ants);
	return (0);
}

int		main(void)
{
	start_reading();
	// system("leaks lem-in");
	return (0);
}