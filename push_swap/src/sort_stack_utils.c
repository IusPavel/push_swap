#include "push_swap.h"

static void	to_be_zero(t_stack *a, int len)
{
	while (len--)
	{
		a->to_b = 0;
		a = a->next;
	}
}

void	mark_max(t_stack *a)
{
	t_stack	*ptr;
	int		i;
	int		len;

	ptr = a;
	i = -2147483648;
	len = stack_len(a);
	while (len--)
	{
		if (a->n > i)
		{
			i = a->n;
			ptr = a;
		}
		a = a->next;
	}
	ptr->max = 1;
}

int	find_max_len(t_stack *a, int len)
{
	int	i;
	int	max;

	i = 0;
	max = a->n;
	to_be_zero(a, len);
	while (len--)
	{
		if (max <= a->n)
		{
			i++;
			max = a->n;
		}
		else
			a->to_b = 1;
		a = a->next;
	}
	return (i);
}

int	find_max_len_without_tobe(t_stack *a, int len)
{
	int	i;
	int	max;

	i = 0;
	max = a->n;
	while (len--)
	{
		if (max <= a->n)
		{
			i++;
			max = a->n;
		}
		a = a->next;
	}
	return (i);
}
