/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:11:58 by jonny             #+#    #+#             */
/*   Updated: 2021/05/04 12:14:13 by jonny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	move_top(t_lst *stack_a, t_lst *stack_b, int *pos, char *buf)
{
	if (*pos <= stack_a->len / 2)
	{
		while (*pos > 0)
		{
			exec_inst(stack_a, stack_b, RA, buf);
			(*pos)--;
		}
	}
	else
	{
		while (*pos < stack_a->len)
		{
			exec_inst(stack_a, stack_b, RRA, buf);
			(*pos)++;
		}
	}
	*pos = 0;
}

int	get_first(t_lst *a, int *tab, int i, int chunk_index)
{
	t_pointer	node_a;
	init_pointer(a, &node_a);
	int hold_first;

	hold_first = -1;
	while (node_a.ptr && node_a.pos <= a->len / 2)
	{
		if (node_a.ptr->nb >= tab[i] && node_a.ptr->nb <= tab[i + chunk_index - 1])
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
	init_pointer(a, &node_a);
	int hold_second;

	hold_second = -1;
	node_a.ptr = a->tail;
	node_a.pos = a->len - 1; 
	while (node_a.ptr && node_a.pos <= a->len / 2)
	{
		if (node_a.ptr->nb >= tab[i] && node_a.ptr->nb <= tab[i + chunk_index - 1])
		{
			break ;
		}
		incr_pointer(&node_a);
	}
	return (hold_second);
}

t_lst	*sort_b(t_lst *a, t_lst *b, char *buf)
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
			if (node_b.pos <= b->len / 2)
			{
				while (node_b.pos)
				{
					exec_inst(b, NULL, RB, buf);
					// print_stacks(a, b);
					node_b.pos--;
				}
			}
			else if (node_b.pos > b->len / 2)
			{
				while (node_b.pos < b->len)
				{
					exec_inst(b, NULL, RRB, buf);
					// print_stacks(a, b);
					node_b.pos++;
				}
			}
			exec_inst(b, a, PA, buf);
			// print_stacks(a, b);
			init_pointer(b, &node_b);
			i--;
			continue ;
		}
		node_b.ptr = node_b.ptr->next;
		node_b.pos++; 
	}
	free(tab);
	return (a);
}	

int	sort_a(t_lst *a, t_lst *b, char *buf)
{
	int *tab;
	int	i;
	int nb_elem;
	int hold_first;
	int hold_second;
	int chunk_index;

	if (a->len == 100 || a->len == 500)
		chunk_index = 25;
	else
		chunk_index = 10;
	tab = get_chunk_array(a);
	nb_elem = a->len;
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
	free(tab);
	return (1);
}	

/*
** Simple algo to sort 3 numbers
*/
void	sort_3numbers(t_lst *stack, char *buf)
{
	int		next_nb;
	int		tab[3];

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
