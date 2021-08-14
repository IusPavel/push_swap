#include "push_swap.h"

void	shift_stack(t_stack **a)
{
	int		i;
	t_stack	*ptr;

	i = 0;
	ptr = *a;
	while (ptr->prev->max != 1)
	{
		i++;
		ptr = ptr->next;
	}
	if (i > (stack_len(ptr) / 2))
	{
		i = stack_len(ptr) - i;
		while (i--)
			reverse_rotate_stack(a, "rra");
	}
	else
		while (i--)
			rotate_stack(a, "ra");
}
