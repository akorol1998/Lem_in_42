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
		if (!ft_strcmp(line, "##start"))
			break ;
		ants = ft_atoi(line);
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
		;
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

void		reading_rooms(t_table *tbl)
{
	char	*line;
	char	**data;
	int		flag;
	int		k;

	flag = 1;
	line = NULL;
	while (flag)
	{
		get_next_line(0, &line);
		data = ft_strsplit(line, ' ');
		free(line);
		k = -1;
		if (check_room(data))
		{
			flag = 0;
			for(int j = 0;j < 3;j++)
				printf("%s\n", data[j]);
		}
	}
}

int			start_reading(void)
{
	t_table	*table;
	t_node	*node;
	int		ants;

	table = create_table();
	node = create_node()
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