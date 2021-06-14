/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:11:58 by jonny             #+#    #+#             */
/*   Updated: 2021/06/14 12:24:54 by jonny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
			if (node_b.pos <= b->len / 2)
			{
				while (node_b.pos)
				{
					exec_inst(b, NULL, RB, buf);
					node_b.pos--;
				}
			}
			else if (node_b.pos > b->len / 2)
			{
				while (node_b.pos < b->len)
				{
					exec_inst(b, NULL, RRB, buf);
					node_b.pos++;
				}
			}
			exec_inst(b, a, PA, buf);
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

int	sort_a(t_lst *a, t_lst *b, char **buf)
{
	int	*tab;
	int	i;
	int	nb_elem;
	int	hold_first;
	int	hold_second;
	int	chunk_index;

	chunk_index = get_chunk_size(a->len);
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
