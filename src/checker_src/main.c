#include "../../includes/checker.h"

void	init_input(char **input, t_lst *stack_a)
{
	input = NULL;
	stack_a = NULL;
}

int	main(int argc, char **argv)
{
	char		**args;
	char		*input;
	t_lst		*stack_a;

	input = NULL;
	stack_a = NULL;
	args = NULL;
	if (argc > 1)
	{
		args = parse_args(argc, argv);
		init_input(&input, stack_a);
		if (!check_args_errors(args))
		{
			if (init_stack(&stack_a, args))
				return (EXIT_FAILURE);
			if (get_instructions(&input) >= 0 && !check_instructions(input))
				checker(stack_a, input);
		}
		free_all(stack_a, args, input);
	}
	else
		ft_putendl_fd("Error", STDERR_FILENO);
	return (EXIT_SUCCESS);
}
