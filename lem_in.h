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
	// char				**vert;	// shortest way
	struct s_node		**q;	// Previous node's name
	struct s_node		*nodes;	// all the available nodes
	struct s_node		*start;
	struct s_node		*end;
	struct s_node		***path;
	// char				**unvis;	// unvisited nodes
	int					ants;	// Number of ants
	int					rooms;

}						t_table;		// have to use linked list to handle unpredictable number of rooms


typedef struct			s_node
{
	struct s_pipe		*branch;
	struct s_node		*link;
	struct s_node		*prev;
	int					weight;
	int					current;
	int					*pos;	// to check duplicated coordinates
	char				*name;
	int					lem;
	char				visited;
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
int						creating_arrays(t_table *tbl);
int						launch_algorithm(t_table *tbl);
int						list_len(char **list);
int						set_levels(t_table *tbl);
int						extract_path(t_table *tbl, int idx);
int						display_ants(t_table *tbl);
int						count_nodes(t_table *tbl, int idx);
int						parsing_ants(t_table *tbl);
int						len_arr(t_node **nodes, t_node ***arr);
int						finish_ants(t_node **node, int ants);
int						end_part_of_parsing(t_table *tbl, int count);
#endif