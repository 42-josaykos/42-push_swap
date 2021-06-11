/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonny <josaykos@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:24:23 by jonny             #+#    #+#             */
/*   Updated: 2021/04/30 11:32:44 by jonny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>
# include "../libft/includes/libft.h"

# define BUF_SIZE 100000

enum e_order
{
	ASCENDING,
	DESCENDING,
};

enum e_inst
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

typedef struct s_lst	t_lst;

typedef struct s_node
{
	int				nb;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

struct	s_lst
{
	t_node		*head;
	t_node		*tail;
	int			median;
	size_t		len;
};

typedef struct s_data
{
	char	*inst;
}	t_data;

/*
** stack_init, stack_utils
*/
int		init_stack(t_lst **stack, char **argv);
void	free_stack(t_lst *stack);
void	append(t_lst *stack, int nb);
void	prepend(t_lst *stack, int nb);
void	remove_head(t_lst *stack);
void	remove_tail(t_lst *stack);
int		is_sorted(t_lst *stack, enum e_order order);
void	to_array(t_lst *stack, int *array);

/*
** swap, reverse_rotate, push
*/
void	swap(t_lst *stack);
void	rotate(t_lst *stack);
void	reverse_rotate(t_lst *stack);
void	push(t_lst *src_stack, t_lst *dst_stack);

/*
** parsing
*/
char	**parse_args(int argc, char **argv);

/*
** strings
*/
bool	is_number(char *str);
int		get_instructions(char **input);
void	print_stacks(t_lst *stack_a, t_lst *stack_b);

/*
** arrays
*/
int		strslen(char **array);
void	free_2darray(char **array);
int		get_median(t_lst *stack);
void	bubble_sort(int *arr, int n);

/*
** errors
*/
int		check_args_errors(char **args);

/*
** free_all
*/
void	free_all(t_lst *stack_a, char **args, char *input);

#endif
