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

#ifndef LEM_IN_H
# define LEM_IN_H
# include "printf/ft_printf.h"
# include <errno.h>

typedef struct			s_table
{
	struct s_node		**q;
	struct s_node		*nodes;
	struct s_node		*start;
	struct s_node		*end;
	struct s_node		***path;
	int					ants;
	int					rooms;
	char				*msg;
	char				*map;

}						t_table;

typedef struct			s_node
{
	struct s_pipe		*branch;
	struct s_node		*link;
	struct s_node		*prev;
	int					weight;
	int					current;
	int					*pos;
	char				*name;
	int					lem;
	char				visited;
}						t_node;

typedef struct			s_pipe
{
	t_node				*node;
	struct s_pipe		*next;
}						t_pipe;

void					print_list(t_table *tbl);
t_table					*create_table();
int						get_ants(t_table *tbl);
char					*reading_rooms(t_table *tbl);
int						ant_check(char	*line);
t_node					*create_node(void);
int						setting_level(t_table *tbl, t_node *cur);
int						check_room(char **data, t_table *tbl);
int						fill_node(char **data, t_node *node, t_table *tbl);
int						read_line(t_table *tbl, char c);
int						check_line(char *line, t_table *tbl);
int						check_num(char **data, t_table *tbl);
int						check_for_links(char **data, t_table *tbl);
int						reading_links(char *line0, t_table *tbl);
int						linking(char **data, t_table *tbl);
int						connecting_nodes(t_node *node, t_node *node2);
int						connect_node2(t_node *node2, t_node *node);
int						arr_and_algo(t_table *tbl);
int						creating_arrays(t_table *tbl);
int						start_reading(t_table *tbl);
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
int						make_decision(t_table *tbl, int idx);
int						move_ants(t_node **arr, int *ant);
int						what_to_do(int ant, t_table *tbl, int *i, int *f);
void					swarming(t_table *tbl);
void					finish_rest(t_table *tbl, int i);
int						check_link(t_table *tbl);
void					join_map(t_table *tbl, char *line);
void					clean_function(t_table *tbl);
int						room_in_path(t_table *tbl);
void					recursive_node(t_table *tbl, t_node *node);
int						check_valid_line(char *line, t_table *tbl);
void					add_to_queue(t_table *tbl, t_node *cur);
void					really_add(t_node *cur, t_pipe *pip,
t_table *tbl, int *idx);
#endif
