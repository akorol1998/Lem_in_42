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
	int		a;
	char	*line;

	ants = 0;
	line = NULL;
	while (1)
	{
		if (!(a = get_next_line(0, &line)) || a == -1)
			break ;
		join_map(tbl, line);
		if (ant_check(line))
		{
			ants = ft_atoi(line);
			break ;
		}
		if (line[0] == '#' && ft_strchr(line, ':'))
			tbl->msg = !tbl->msg ? ft_strdup(line) : NULL;
		if (!ft_strcmp(line, "##start"))
			break;
		free(line);
	}
	free(line);
	if (ants < 0 || !ants)
	{
		ft_printf("Something is wrong\n");
		return (0);
	}
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

// freeing data
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
	{
		return (0);
	}
	return (1);
}

char		*reading_rooms(t_table *tbl)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		join_map(tbl, line);
		if (line[0] == '#' && ft_strchr(line, ':'))
			tbl->msg = !tbl->msg ? ft_strdup(line) : NULL;
		
		if (line[0] != '#' && ft_strchr(line, '-'))
			return (line);
		if (!check_line(line, tbl))
		{
			free(line);
			ft_printf("here");
			return (NULL);
		}
		free(line);
	}
	ft_printf("hello\n");
	return (NULL);
}

int			start_reading(t_table *tbl)
{
	char	*line;
	int		flag;

	if (!get_ants(tbl))
	{
		clean_function(tbl);
		return (0);
	}		
	flag = 0;
	if ((line = reading_rooms(tbl)) && tbl->start && tbl->end)
	{
		ft_printf("{%s}\n", line);
		if (!reading_links(line, tbl))
		{
			ft_printf("Bad links\n");
			free(line);
			clean_function(tbl);
			return (0);
		}
		free(line);
		creating_arrays(tbl);
		printf("%s\n", tbl->map);
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
			ft_printf(" Darova %s\n", strerror(EINVAL)); // Another type of error needed
			return (0);
		}
	}
	else
		ft_printf("No Start or\n no End or\n some another unknown ERROR\n");
	clean_function(tbl);
	return (0);
}

int			main(void)
{
	t_table	*tbl;

	tbl = create_table();
	if (!start_reading(tbl))
		ft_printf("%s\n", strerror(EINVAL));
	system("leaks lem-in");
	return (0);
}