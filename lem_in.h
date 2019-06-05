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
	struct s_node		*start;
	struct s_node		*end;
	char				**vis;		// visited nodes
	char				**unvis;	// unvisited nodes
	int					ants;	// Number of ants
	int					rooms;

}						t_table;		// have to use linked list to handle unpredictable number of rooms


typedef struct			s_node
{
	struct s_pipe		*branch;
	struct s_node		*link;
	int					weight;
	int					current;
	int					*pos;	// to check duplicated coordinates
	char				*name;
}						t_node;

typedef struct			s_pipe
{
	t_node				*node;
	struct s_pipe		*next;
}						t_pipe;

void					print_list(t_table *tbl); // delete this
t_table					*create_table();
int						ant_check(char	*line);
t_node					*create_node(void);
int						check_room(char **data);
int						fill_node(char **data, t_node *node, t_table *tbl);
int						read_line(t_table *tbl, char c);
int						check_line(char *line, t_table *tbl);
int						check_num(char **data);
int						check_for_links(char **data, t_table *tbl);
int						reading_links(char *line0, t_table *tbl);
int						linking(char **data, t_table *tbl);
int						connecting_nodes(t_node *node, t_node *node2);
int						connect_node2(t_node *node2, t_node *node);
#endif