/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:11:58 by jonny             #+#    #+#             */
/*   Updated: 2021/06/18 13:55:31 by jonny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_b_loop(t_pointer *node_b, t_lst *b, t_lst *a)
{
	if ((*node_b).pos <= b->len / 2)
	{
		while ((*node_b).pos)
		{
			exec_inst(b, NULL, RB);
			(*node_b).pos--;
		}
	}
	else if ((*node_b).pos > b->len / 2)
	{
		while ((*node_b).pos < b->len)
		{
			exec_inst(b, NULL, RRB);
			(*node_b).pos++;
		}
	}
	exec_inst(b, a, PA);
	init_pointer(b, node_b);
}

t_lst	*sort_b(t_lst *a, t_lst *b)
{
	int			*tab;
	int			i;
	t_pointer	node_b;

	init_pointer(b, &node_b);
	tab = get_chunk_array(b);
	i = b->len - 1;
	while (i >= 0 && node_b.ptr)
	{
		if (node_b.ptr->nb == tab[i])
		{
			sort_b_loop(&node_b, b, a);
			i--;
			continue ;
		}
		node_b.ptr = node_b.ptr->next;
		node_b.pos++;
	}
	free(tab);
	return (a);
}	

void	sort_a_loop_2(t_lst *a, t_lst *b, int *chunk, int size)
{
	a->hold_first = 0;
	a->hold_second = a->len - 1;
	while (a->hold_first != -1 || a->hold_second != -1)
	{
		a->hold_first = get_first(a, chunk, size);
		a->hold_second = get_second(a, chunk, size);
		if (a->hold_first < a->len - a->hold_second)
		{
			while (a->hold_first)
			{
				exec_inst(a, NULL, RA);
				a->hold_first--;
			}
			exec_inst(a, b, PB);
		}
		else if (a->hold_second != -1)
		{
			while (a->hold_second < a->len)
			{
				exec_inst(a, NULL, RRA);
				a->hold_second++;
			}
			exec_inst(a, b, PB);
		}
	}
}

void	sort_a_loop_1(t_lst *a, t_lst *b)
{
	int	i;
	int	last_chunk;
	int	max_chunks;

	i = 0;
	max_chunks = a->nb_chunks;
	if (a->last_chunk_size != 0)
		max_chunks = a->nb_chunks - 1;
	while (i < max_chunks)
	{
		sort_a_loop_2(a, b, a->chunks[i], a->chunk_size);
		i++;
	}
	if (a->last_chunk_size != 0)
		sort_a_loop_2(a, b, a->chunks[i], a->last_chunk_size);
}

int	sort_a(t_lst *a, t_lst *b)
{
	int	*tab;

	get_chunk_array2(a);
	sort_a_loop_1(a, b);
	free_chunk_arrays(a);
	return (1);
}	
