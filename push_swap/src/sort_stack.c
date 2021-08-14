#include "push_swap.h"

static int	need_to_be(t_stack *a)
{
	int	start;

	start = a->n;
	if (a->to_b == 1)
		return (1);
	a = a->next;
	while (a->n != start)
	{
		if (a->to_b == 1)
			return (1);
		a = a->next;
	}
	return (0);
}

static int	short_way(t_stack *a, int len)
{
	int		temp;
	int		length;
	int		best_len;
	int		mem;
	t_stack	*start_of_best_len;

	temp = len;
	mem = 0;
	length = len;
	start_of_best_len = a;
	while (length--)
	{
		best_len = find_max_len(a, len);
		if (best_len > mem)
		{
			start_of_best_len = a;
			mem = best_len;
		}
		a = a->next;
	}
	find_max_len(start_of_best_len, temp);
	return (mem);
}

static int	keep_a(t_stack *a)
{
	int	i;
	int	start;

	i = 0;
	start = a->n;
	if (a->to_b == 0)
		i++;
	a = a->next;
	while (a->n != start)
	{
		if (a->to_b == 0)
			i++;
		a = a->next;
	}
	return (i);
}

static int	need_to_swap(t_stack *a)
{
	int	len;

	len = keep_a(a);
	swap_stack(&a, 0);
	if (len < find_max_len_without_tobe(a, stack_len(a)))
	{
		swap_stack(&a, 0);
		return (1);
	}
	else
	{
		swap_stack(&a, 0);
		return (0);
	}
}

void	sort_stack(t_stack **a, int len)
{
	t_stack	*b;

	if (is_sorted(*a))
		exit(0);
	b = 0;
	short_way(*a, len);
	mark_max(*a);
	while (need_to_be(*a))
	{
		if (need_to_swap(*a))
		{
			swap_stack(a, "sa");
			find_max_len(*a, stack_len(*a));
		}
		else if ((*a)->to_b == 0)
			rotate_stack(a, "ra");
		else
			push_stack(a, &b, "pb");
	}
	selection(a, &b);
	shift_stack(a);
}
