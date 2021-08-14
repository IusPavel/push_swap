#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	int	first;

	if (!a || a->n == a->next->n)
		return (1);
	first = a->n;
	if (a->n > a->next->n)
		return (0);
	a = a->next;
	while (a->next->n != first)
	{
		if (a->n > a->next->n)
			return (0);
		a = a->next;
	}
	return (1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (1)
	{
		if ((s1[i] != s2[i]) || !s1[i] || !s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
}

int	stack_len(t_stack *a)
{
	int		i;
	int		start;
	t_stack	*ptr;

	if (!a)
		return (0);
	i = 1;
	ptr = a;
	start = ptr->n;
	while (ptr->next->n != start)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}

static t_stack	*add_element(int data)
{
	t_stack	*begin;

	begin = (t_stack *)malloc(sizeof(t_stack));
	if (!begin)
		exit(EXIT_FAILURE);
	begin->n = data;
	begin->to_b = 0;
	begin->max = 0;
	begin->prev = begin;
	begin->next = begin;
	return (begin);
}

void	fill_stack(t_stack **lst, int len, int *arguments)
{
	t_stack	*new;

	*lst = add_element(arguments[len - 1]);
	while (len > 1)
	{
		new = add_element(arguments[len - 2]);
		new->next = *lst;
		new->prev = (*lst)->prev;
		(*lst)->prev->next = new;
		(*lst)->prev = new;
		(*lst) = new;
		len--;
	}
}
