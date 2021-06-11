/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:55:45 by jonny             #+#    #+#             */
/*   Updated: 2021/04/13 10:33:13 by jonny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	swap(t_lst *stack)
{
	int		tmp;
	t_node	*head_ptr;

	if (stack && stack->len > 1)
	{
		head_ptr = stack->head;
		tmp = head_ptr->nb;
		head_ptr->nb = head_ptr->next->nb;
		head_ptr->next->nb = tmp;
	}
}
