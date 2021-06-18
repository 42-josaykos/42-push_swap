/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:11:58 by jonny             #+#    #+#             */
/*   Updated: 2021/06/18 10:54:04 by jonny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_b_loop(t_pointer *node_b, t_lst *b, t_lst *a, char **buf)
{
	if ((*node_b).pos <= b->len / 2)
	{
		while ((*node_b).pos)
		{
			exec_inst(b, NULL, RB, buf);
			(*node_b).pos--;
		}
	}
	else if ((*node_b).pos > b->len / 2)
	{
		while ((*node_b).pos < b->len)
		{
			exec_inst(b, NULL, RRB, buf);
			(*node_b).pos++;
		}
	}
	exec_inst(b, a, PA, buf);
	init_pointer(b, node_b);
}

t_lst	*sort_b(t_lst *a, t_lst *b, char **buf)
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
			sort_b_loop(&node_b, b, a, buf);
			i--;
			continue ;
		}
		node_b.ptr = node_b.ptr->next;
		node_b.pos++;
	}
	free(tab);
	return (a);
}	

void	sort_a_loop_2(t_lst *a, t_lst *b, int i, char **buf)
{
	a->hold_first = 0;
	a->hold_second = a->len - 1;
	while (a->hold_first != -1 || a->hold_second != -1)
	{
		a->hold_first = get_first(a, a->tab, i, a->chunk_size);
		a->hold_second = get_second(a, a->tab, i, a->chunk_size);
		if (a->hold_first < a->len - a->hold_second)
		{
			while (a->hold_first)
			{
				exec_inst(a, NULL, RA, buf);
				a->hold_first--;
			}
			exec_inst(a, b, PB, buf);
		}
		else if (a->hold_second != -1)
		{
			while (a->hold_second < a->len)
			{
				exec_inst(a, NULL, RRA, buf);
				a->hold_second++;
			}
			exec_inst(a, b, PB, buf);
		}
	}
}

void	sort_a_loop_1(t_lst *a, t_lst *b, char **buf)
{
	int	i;
	int	nb_elem;

	nb_elem = a->len;
	a->chunk_size = get_chunk_size(a->len);
	i = 0;
	while (a->len > 0)
	{
		sort_a_loop_2(a, b, i, buf);
		if (i + a->chunk_size >= nb_elem)
			i += (nb_elem - 1);
		else
			i += a->chunk_size;
	}
}

int	sort_a(t_lst *a, t_lst *b, char **buf)
{
	int	*tab;

	a->tab = get_chunk_array(a);
	// get_chunk_array2(a);
	sort_a_loop_1(a, b, buf);
	free(a->tab);
	return (1);
}	
