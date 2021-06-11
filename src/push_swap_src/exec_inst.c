/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_inst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 14:04:35 by jonny             #+#    #+#             */
/*   Updated: 2021/04/16 14:22:29 by jonny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	exec_inst3(t_lst *src, t_lst *dst, enum e_inst inst, char *buf)
{
	if (inst == RRA || inst == RRB)
	{
		reverse_rotate(src);
		if (inst == RRA)
			ft_strcat(buf, "rra\n");
		else if (inst == RRB)
			ft_strcat(buf, "rrb\n");
	}
	else if (inst == RRR)
	{
		reverse_rotate(src);
		reverse_rotate(dst);
		ft_strcat(buf, "rrr\n");
	}
}

void	exec_inst2(t_lst *src, t_lst *dst, enum e_inst inst, char *buf)
{
	if (inst == RA || inst == RB)
	{
		rotate(src);
		if (inst == RA)
			ft_strcat(buf, "ra\n");
		else if (inst == RB)
			ft_strcat(buf, "rb\n");
	}
	else if (inst == RR)
	{
		rotate(src);
		rotate(dst);
		ft_strcat(buf, "rr\n");
	}
	else
		exec_inst3(src, dst, inst, buf);
}

void	exec_inst(t_lst *src, t_lst *dst, enum e_inst inst, char *buf)
{
	if (inst == SA || inst == SB)
	{
		swap(src);
		if (inst == SA)
			ft_strcat(buf, "sa\n");
		else if (inst == SB)
			ft_strcat(buf, "sb\n");
	}
	else if (inst == SS)
	{
		swap(src);
		swap(dst);
		ft_strcat(buf, "ss\n");
	}
	else if (inst == PA || inst == PB)
	{
		push(src, dst);
		if (inst == PA)
			ft_strcat(buf, "pa\n");
		else if (inst == PB)
			ft_strcat(buf, "pb\n");
	}
	else
		exec_inst2(src, dst, inst, buf);
}
