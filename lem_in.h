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
# include "limits.h"

typedef struct 			s_table
{
	struct s_node		**q;	// Previous node's name
	struct s_node		*nodes;	// all the available nodes
	struct s_node		*start;
	struct s_node		*end;
	struct s_node		***path;
	int					ants;	// Number of ants
	int					rooms;

}						t_table;		// have to use linked list to handle unpredictable number of rooms


typedef struct			s_node
{
	struct s_pipe		*branch;
	struct s_node		*link;
	struct s_pipe		*prev;
	struct s_node		**pre_arr;
	struct s_node		**vert;
	int					level;
	int					*pos;	// to check duplicated coordinates
	char				*name;
	int					lem;
	int					in;
	int					out;
	char				visited;
}						t_node;

typedef struct			s_pipe
{
	t_node				*node;
	struct s_pipe		*next;
}						t_pipe;

t_node		*g_node;

void					print_list(t_table *tbl); // delete this
void					count_pip(t_table *tbl, t_node *node); // delete this
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
int						finish_rest(t_table *tbl, int idx);
int						setting_levels(t_table *tbl, t_node *cur);
void					add_to_queue(t_table *tbl, t_node *cur);
void					directions(t_table *tbl);
void					in_and_out(t_table *tbl);
void					bad_links(t_table *tbl);
void					data_tunage(t_table *tbl);
int						bad_in_outs(t_table *tbl, int sign);
void					in_out_to_zero(t_table *tbl);
void					forming_queue(t_table *tbl);
void					queue_up(t_table *tbl, t_node *cur);
void					add_to_prev(t_table *tbl, t_node *node, t_node *prev);
void					delete_input_forks(t_table *tbl);
void					checking_in_forks(t_node *node);
void					delete_fork_func(t_node *pre, t_node *node);
void					delete_output_forks(t_table *tbl);
void					remove_out_links(t_table *tbl, t_node *node);
void					refresh_outs(t_table *tbl);
void					short_way(int *arr, t_node *node, t_table *tbl, int idx);
void					delete_long_paths(int *arr, t_node *node, int size);
void					delete_links(t_node *node, t_node *save);
void					fill_paths(t_table *tbl);
int						make_decision(t_table *tbl, int idx);
void					parse_lems(t_table *tbl);
t_node					*bad_input_link(t_pipe *prev, t_node *node);
void					save_links(t_table *tbl);
void					add_branches(t_table *tbl);
void					delete_from_vert(t_node *node, int idx);
void					prev_to_arr(t_table *tbl);
void					free_prev_links(t_table *tbl);
void					clean_branch(t_pipe *pip);
#endif