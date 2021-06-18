/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 10:55:48 by jonny             #+#    #+#             */
/*   Updated: 2021/06/18 13:45:39 by jonny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_chunk_size(int len)
{
	int	i;

	if (len >= 200)
		return (50);
	else if (len >= 100)
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
void	sort_3numbers(t_lst *stack)
{
	int		tab[3];

	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	to_array(stack, tab);
	if (tab[0] > tab[1] && tab[2] > tab[0])
		exec_inst(stack, NULL, SA);
	else if (tab[0] > tab[1] && tab[1] > tab[2])
	{
		exec_inst(stack, NULL, SA);
		exec_inst(stack, NULL, RRA);
	}
	else if (tab[0] > tab[1] && tab[0] > tab[2])
		exec_inst(stack, NULL, RA);
	else if (tab[1] > tab[0] && tab[1] > tab[2] && tab[0] < tab[2])
	{
		exec_inst(stack, NULL, SA);
		exec_inst(stack, NULL, RA);
	}
	else if (tab[1] > tab[0] && tab[1] > tab[2] && tab[0] > tab[2])
		exec_inst(stack, NULL, RRA);
	return ;
}

void	move_top(t_lst *stack_a, t_lst *stack_b, int *pos)
{
	if (*pos <= stack_a->len / 2)
	{
		while (*pos > 0)
		{
			exec_inst(stack_a, stack_b, RA);
			(*pos)--;
		}
	}
	else
	{
		while (*pos < stack_a->len)
		{
			exec_inst(stack_a, stack_b, RRA);
			(*pos)++;
		}
	}
	*pos = 0;
}

int	get_first(t_lst *a, int *chunk, int size)
{
	t_pointer	node_a;
	int			hold_first;
	int			i;

	init_pointer(a, &node_a);
	hold_first = -1;
	while (node_a.ptr && node_a.pos <= a->len / 2)
	{
		i = 0;
		while (i < size)
		{
			if (node_a.ptr->nb == chunk[i])
			{
				hold_first = node_a.pos;
				return (hold_first);
			}
			i++;
		}
		incr_pointer(&node_a);
	}
	return (hold_first);
}

int	get_second(t_lst *a, int *chunk, int size)
{
	t_pointer	node_a;
	int			hold_second;
	int			i;

	init_pointer(a, &node_a);
	hold_second = -1;
	node_a.ptr = a->tail;
	node_a.pos = a->len - 1;
	while (node_a.ptr && node_a.pos >= a->len / 2)
	{
		i = 0;
		while (i < size)
		{
			if (node_a.ptr->nb == chunk[i])
			{
				hold_second = node_a.pos;
				return (hold_second);
			}
			i++;
		}
		decr_pointer(&node_a);
	}
	return (hold_second);
}
