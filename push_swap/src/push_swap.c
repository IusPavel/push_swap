#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	int		len;
	int		*numbers;
	char	**arguments;

	a = 0;
	arguments = argv_parser(argc, argv);
	len = mastoi(&numbers, arguments);
	check_stack(len, numbers);
	fill_stack(&a, len, numbers);
	sort_stack(&a, len);
	return (0);
}
