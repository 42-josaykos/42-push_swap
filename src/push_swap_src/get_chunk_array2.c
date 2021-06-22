/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_chunk_array2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 13:27:55 by jonny             #+#    #+#             */
/*   Updated: 2021/06/22 13:49:19 by jonny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	get_chunk_array22(t_lst *stack, int *tab)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < stack->nb_chunks)
	{
		stack->chunks[i] = ft_calloc(stack->chunk_size, sizeof(int));
		i++;
	}
	i = 0;
	k = 0;
	while (i < stack->chunk_size)
	{
		j = 0;
		while (j < stack->chunk_size && k < stack->len)
		{
			stack->chunks[i][j] = tab[k];
			j++;
			k++;
		}
		i++;
	}
}

void	get_chunk_array2(t_lst *stack)
{
	int	*tab;

	tab = ft_calloc(stack->len, sizeof(int));
	to_array(stack, tab);
	bubble_sort(tab, stack->len);
	stack->chunk_size = get_chunk_size(stack->len);
	stack->nb_chunks = stack->len / stack->chunk_size;
	stack->last_chunk_size = stack->len % stack->chunk_size;
	if (stack->last_chunk_size)
		stack->nb_chunks++;
	stack->chunks = ft_calloc(stack->nb_chunks, sizeof(int *));
	get_chunk_array22(stack, tab);
	free(tab);
}

void	decr_pointer(t_pointer *node)
{
	node->ptr = node->ptr->prev;
	node->pos--;
}
