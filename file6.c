#include "lem_in.h"

int			setting_levels(t_node *cur, t_table **tbl)
{
	int		idx;

	idx = 0;
	tbl->q[idx] = cur;
	while (cur && ft_strcmp(cur->name, tbl->end->name))
	{
		add_to_queue(tbl, cur);
		cur = tbl->q[++idx];
	}
	if (!tbl->q[idx])
		return (-1);
	return (1);
}