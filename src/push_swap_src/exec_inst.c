/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_inst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 14:04:35 by jonny             #+#    #+#             */
/*   Updated: 2021/06/18 12:23:03 by jonny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <unistd.h>

void	exec_inst3(t_lst *src, t_lst *dst, enum e_inst inst, char **buf)
{
	if (inst == RRA || inst == RRB)
	{
		reverse_rotate(src);
		if (inst == RRA)
			ft_realloc(buf, "rra\n");
		else if (inst == RRB)
			ft_realloc(buf, "rrb\n");
	}
	else if (inst == RRR)
	{
		reverse_rotate(src);
		reverse_rotate(dst);
		ft_realloc(buf, "rrr\n");
	}
}

void	exec_inst2(t_lst *src, t_lst *dst, enum e_inst inst, char **buf)
{
	if (inst == RA || inst == RB)
	{
		rotate(src);
		if (inst == RA)
			ft_realloc(buf, "ra\n");
		else if (inst == RB)
			ft_realloc(buf, "rb\n");
	}
	else if (inst == RR)
	{
		rotate(src);
		rotate(dst);
		ft_realloc(buf, "rr\n");
	}
	else
		exec_inst3(src, dst, inst, buf);
}

void	exec_inst(t_lst *src, t_lst *dst, enum e_inst inst, char **buf)
{
	if (inst == SA || inst == SB)
	{
		swap(src);
		if (inst == SA)
			ft_realloc(buf, "sa\n");
		else if (inst == SB)
			ft_realloc(buf, "sb\n");
	}
	else if (inst == SS)
	{
		swap(src);
		swap(dst);
		ft_realloc(buf, "ss\n");
	}
	else if (inst == PA || inst == PB)
	{
		push(src, dst);
		if (inst == PA)
			ft_realloc(buf, "pa\n");
		else if (inst == PB)
			ft_realloc(buf, "pb\n");
	}
	else
		exec_inst2(src, dst, inst, buf);
}
