#include "push_swap.h"
#include "get_next_line.h"

static int	action_ext(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strcmp(line, "rra"))
	{
		reverse_rotate_stack(a, 0);
		return (1);
	}
	else if (!ft_strcmp(line, "rrb"))
	{
		reverse_rotate_stack(b, 0);
		return (1);
	}
	else if (!ft_strcmp(line, "rrr"))
	{
		reverse_rotate_stack(a, 0);
		reverse_rotate_stack(b, 0);
		return (1);
	}
	else if (!ft_strcmp(line, "rr"))
	{
		rotate_stack(a, 0);
		rotate_stack(b, 0);
		return (1);
	}
	return (0);
}

static void	action(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strcmp(line, "pa"))
		push_stack(b, a, 0);
	else if (!ft_strcmp(line, "pb"))
		push_stack(a, b, 0);
	else if (!ft_strcmp(line, "sa"))
		swap_stack(a, 0);
	else if (!ft_strcmp(line, "sb"))
		swap_stack(b, 0);
	else if (!ft_strcmp(line, "ss"))
	{
		swap_stack(a, 0);
		swap_stack(b, 0);
	}
	else if (!ft_strcmp(line, "ra"))
		rotate_stack(a, 0);
	else if (!ft_strcmp(line, "rb"))
		rotate_stack(b, 0);
	else if (action_ext(a, b, line))
		;
	else
		throw_error();
}

static void	move_stack(t_stack *a)
{
	char	*line;
	int		is_read;
	t_stack	*b;

	b = 0;
	is_read = get_next_line(0, &line);
	while (is_read != 0)
	{
		if (is_read == -1)
			exit(EXIT_FAILURE);
		action(&a, &b, line);
		is_read = get_next_line(0, &line);
	}
	if (is_sorted(a) && b == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	int		len;
	int		*numbers;
	char	**arguments;

	if (argc == 1)
		return (0);
	a = 0;
	arguments = argv_parser(argc, argv);
	len = mastoi(&numbers, arguments);
	check_stack(len, numbers);
	fill_stack(&a, len, numbers);
	move_stack(a);
	return (0);
}
