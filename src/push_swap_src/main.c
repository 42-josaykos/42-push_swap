#include "../../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_lst	*stack_a;
	char	**args;

	stack_a = NULL;
	if (argc > 1)
	{
		args = parse_args(argc, argv);
		if (!args)
			return (1);
		if (!check_args_errors(args))
		{
			if (init_stack(&stack_a, args))
			{
				free_2darray(args);
				return (1);
			}
			push_swap(stack_a);
		}
		free_stack(stack_a);
		free_2darray(args);
	}
	return (0);
}
