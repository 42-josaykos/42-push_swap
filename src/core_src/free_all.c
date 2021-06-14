/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:02:49 by jonny             #+#    #+#             */
/*   Updated: 2021/06/14 15:01:22 by jonny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	free_all(t_lst *stack_a, char **args, char *input)
{
	free_stack(stack_a);
	free_2darray(args);
	free(input);
}

char	*ft_realloc(char **dst, char *to_add)
{
	int		len_dst;
	char	*tmp;
	int		len_to_add;

	len_dst = ft_strlen(*dst);
	len_to_add = ft_strlen(to_add);
	if (len_dst)
	{
		tmp = (char *)ft_calloc(1, sizeof(char) * (len_dst + 1));
		ft_strcat(tmp, *dst);
		free(*dst);
		*dst = (char *)ft_calloc(1, sizeof(char) * (len_dst + len_to_add + 1));
		ft_strcat(*dst, tmp);
		ft_strcat(*dst, to_add);
		free(tmp);
	}
	else
	{
		free(*dst);
		*dst = ft_strdup(to_add);
	}
	return (*dst);
}
