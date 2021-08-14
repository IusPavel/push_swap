#include "push_swap.h"

static void	push_common_case(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	temp = *b;
	*b = *a;
	(*a)->prev->next = (*a)->next;
	(*a)->next->prev = (*a)->prev;
	*a = (*a)->next;
	temp->prev->next = *b;
	(*b)->prev = temp->prev;
	temp->prev = *b;
	(*b)->next = temp;
}

void	push_stack(t_stack **a, t_stack **b, char *text)
{
	ft_putendl_fd(text, 1);
	if (*a == 0)
		return ;
	if (*b == 0)
	{
		*b = *a;
		(*a)->prev->next = (*a)->next;
		(*a)->next->prev = (*a)->prev;
		*a = (*a)->next;
		(*b)->prev = *b;
		(*b)->next = *b;
	}
	else if (stack_len(*a) == 1)
	{
		(*b)->prev->next = *a;
		(*a)->prev = (*b)->prev;
		(*a)->next = (*b);
		(*b)->prev = *a;
		*b = *a;
		*a = 0;
	}
	else
		push_common_case(a, b);
}

void	swap_stack(t_stack **a, char *text)
{
	int	temp;

	if (*a == 0 || (*a)->next == *a)
		return ;
	ft_putendl_fd(text, 1);
	temp = (*a)->n;
	(*a)->n = (*a)->next->n;
	(*a)->next->n = temp;
}

void	rotate_stack(t_stack **a, char *text)
{
	if (*a == 0)
		return ;
	ft_putendl_fd(text, 1);
	*a = (*a)->next;
}

void	reverse_rotate_stack(t_stack **a, char *text)
{
	if (*a == 0)
		return ;
	ft_putendl_fd(text, 1);
	*a = (*a)->prev;
}
