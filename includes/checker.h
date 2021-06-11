/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:11:51 by jonny             #+#    #+#             */
/*   Updated: 2021/04/26 11:32:03 by jonny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "utils.h"

/*
** checker
*/
int		check_instructions(char *input);
void	checker(t_lst *stack_a, char *inst);

void	exec_instructions(t_lst *stack_a, t_lst *stack_b, char *inst);
int		get_nb_inst(char *buf);

#endif