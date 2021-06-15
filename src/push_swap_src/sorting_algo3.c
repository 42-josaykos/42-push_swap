/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 10:55:48 by jonny             #+#    #+#             */
/*   Updated: 2021/06/15 11:00:30 by jonny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_chunk_size(int len)
{
	int	i;

	if (len == 100 || len == 500)
		return (25);
	i = len / 2;
	while (i > 1)
	{
		if (len % i == 0)
			return (i);
		i--;
	}
	return (len);
}

/*
** Simple algo to sort 3 numbers
*/
void	sort_3numbers(t_lst *stack, char **buf)
{
	int		tab[3];

	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	to_array(stack, tab);
	if (tab[0] > tab[1] && tab[2] > tab[0])
		exec_inst(stack, NULL, SA, buf);
	else if (tab[0] > tab[1] && tab[1] > tab[2])
	{
		exec_inst(stack, NULL, SA, buf);
		exec_inst(stack, NULL, RRA, buf);
	}
	else if (tab[0] > tab[1] && tab[0] > tab[2])
		exec_inst(stack, NULL, RA, buf);
	else if (tab[1] > tab[0] && tab[1] > tab[2] && tab[0] < tab[2])
	{
		exec_inst(stack, NULL, SA, buf);
		exec_inst(stack, NULL, RA, buf);
	}
	else if (tab[1] > tab[0] && tab[1] > tab[2] && tab[0] > tab[2])
		exec_inst(stack, NULL, RRA, buf);
	return ;
}

void	move_top(t_lst *stack_a, t_lst *stack_b, int *pos, char *buf)
{
	if (*pos <= stack_a->len / 2)
	{
		while (*pos > 0)
		{
			exec_inst(stack_a, stack_b, RA, &buf);
			(*pos)--;
		}
	}
	else
	{
		while (*pos < stack_a->len)
		{
			exec_inst(stack_a, stack_b, RRA, &buf);
			(*pos)++;
		}
	}
	*pos = 0;
}

int	get_first(t_lst *a, int *tab, int i, int chunk_index)
{
	t_pointer	node_a;
	int			hold_first;

	init_pointer(a, &node_a);
	hold_first = -1;
	while (node_a.ptr && node_a.pos <= a->len / 2)
	{
		if (node_a.ptr->nb >= tab[i]
			&& node_a.ptr->nb <= tab[i + chunk_index - 1])
		{
			hold_first = node_a.pos;
			break ;
		}
		incr_pointer(&node_a);
	}
	return (hold_first);
}

int	get_second(t_lst *a, int *tab, int i, int chunk_index)
{
	t_pointer	node_a;
	int			hold_second;

	init_pointer(a, &node_a);
	hold_second = -1;
	node_a.ptr = a->tail;
	node_a.pos = a->len - 1;
	while (node_a.ptr && node_a.pos <= a->len / 2)
	{
		if (node_a.ptr->nb >= tab[i]
			&& node_a.ptr->nb <= tab[i + chunk_index - 1])
		{
			break ;
		}
		incr_pointer(&node_a);
	}
	return (hold_second);
}