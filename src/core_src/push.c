/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:57:32 by jonny             #+#    #+#             */
/*   Updated: 2021/04/14 11:58:13 by jonny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

/*
** pa, pb:
** push top of stack_a on top of stack_b 
** and vice-versa
*/
void	push(t_lst *src_stack, t_lst *dst_stack)
{
	if (src_stack && src_stack->len > 0 && dst_stack)
	{
		prepend(dst_stack, src_stack->head->nb);
		remove_head(src_stack);
	}
}
