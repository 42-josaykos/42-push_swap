/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:11:58 by jonny             #+#    #+#             */
/*   Updated: 2021/06/15 11:26:38 by jonny            ###   ########.fr       */
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

void	sort_a_loop_2()
{

}

void	sort_a_loop_1(t_lst *a, t_lst *b, int *tab, char **buf)
{
	int	i;
	int	hold_first;
	int	hold_second;
	int	nb_elem;
	int	chunk_index;

	nb_elem = a->len;
	chunk_index = get_chunk_size(a->len);
	i = 0;
	while (a->len > 0)
	{
		hold_first = 0;
		hold_second = a->len - 1;
		while (hold_first != -1 || hold_second != -1)
		{
			hold_first = get_first(a, tab, i, chunk_index);
			hold_second = get_second(a, tab, i, chunk_index);
			if (hold_first < a->len - hold_second)
			{
				while (hold_first)
				{
					exec_inst(a, NULL, RA, buf);
					hold_first--;
				}
				exec_inst(a, b, PB, buf);
			}
			else if (hold_second != -1)
			{
				while (hold_second < a->len)
				{
					exec_inst(a, NULL, RRA, buf);
					hold_second++;
				}
				exec_inst(a, b, PB, buf);
			}
		}
		if (i + chunk_index >= nb_elem)
			i += (nb_elem - 1);
		else
			i += chunk_index;
	}

}

int	sort_a(t_lst *a, t_lst *b, char **buf)
{
	int	*tab;

	tab = get_chunk_array(a);
	sort_a_loop_1(a, b, tab, buf);
	free(tab);
	return (1);
}	
