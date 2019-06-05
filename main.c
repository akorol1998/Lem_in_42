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
	free(line);
	if (ants < 0 || !ants)
		return (0);
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
		k = -1;
		while (data && data[++k])
			free(data[k]);
		free(data);
		return (0);
	}
	else if (!check_num(data))
		return (0);
	return (1);
}

char		*reading_rooms(t_table *tbl)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		if (ft_strchr(line, '-'))
			return (line);
		if (!check_line(line, tbl))
		{
			free(line);
			return (NULL);
		}
		free(line);
	}
	return (NULL);
}

int			start_reading(void)
{
	t_table	*table;
	char	*line;
	int		flag;

	table = create_table();
	get_ants(table);
	flag = 0;
	if ((line = reading_rooms(table)) && table->start && table->end)
	{

		flag = reading_links(line, table);
		print_list(table);
		// system("leaks lem-in");
	}
	else
		printf("not valid\n");
	if (flag)
		printf("Proceed with algorithm\n");
	return (0);
}

int		main(void)
{
	start_reading();
	return (0);
}