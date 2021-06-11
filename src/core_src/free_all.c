/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:02:49 by jonny             #+#    #+#             */
/*   Updated: 2021/04/16 12:21:33 by jonny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	free_all(t_lst *stack_a, char **args, char *input)
{
	free_stack(stack_a);
	free_2darray(args);
	free(input);
}
