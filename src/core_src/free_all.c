/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:02:49 by jonny             #+#    #+#             */
/*   Updated: 2021/06/14 12:16:18 by jonny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	free_all(t_lst *stack_a, char **args, char *input)
{
	free_stack(stack_a);
	free_2darray(args);
	free(input);
}

char		*ft_strcpy(char *dst, char *src)
{
	int		i;

	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = 0;
	return (dst);
}

char		*ft_realloc(char *dst, char *to_add)
{
	int		len_dst;
	char	*tmp;
	int		len_to_add;

	len_dst = ft_strlen(dst);
	len_to_add = ft_strlen(to_add);
	tmp = (char *)ft_calloc(1, sizeof(char) * (len_dst + 1));
	if (!tmp)
	{
		if (dst)
			free(dst);
		return (NULL);
	}
	if (dst)
		tmp = ft_strcpy(tmp, dst);
	dst = (char *)malloc(sizeof(char) * (len_dst + len_to_add + 1));
	if (!dst)
	{
		if (tmp)
			free(tmp);
		return (NULL);
	}
	dst = ft_strcpy(dst, tmp);
	dst = ft_strcat(dst, to_add);
	free(tmp);
	return (dst);
}
