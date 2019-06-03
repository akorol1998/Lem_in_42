/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 12:50:10 by akorol            #+#    #+#             */
/*   Updated: 2019/06/03 12:50:12 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft/libft.h"

typedef struct 			s_table
{
	int					*way;	// shortest way
	char				**prev;	// Previous node's name
	struct s_node		*nodes;	// all the available nodes
	char				**vis;		// visited nodes
	char				**unvis;	// unvisited nodes
	int					ants;	// Number of ants

}						t_table;		// have to use linked list to handle unpredictable number of rooms


typedef struct			s_node
{
	struct s_node		**branch;
	int					weight;
	int					current;
	int					**pos;	// to check duplicated coordinates
	char				*name;
}						t_node;

t_table					*create_table();

#endif