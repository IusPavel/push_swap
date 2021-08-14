#include "push_swap.h"

static int	find_overlap(t_select mask)
{
	int	overlap;

	overlap = 0;
	while ((mask.a_up)-- && (mask.b_up)--)
		overlap++;
	while ((mask.a_down)-- && (mask.b_down)--)
		overlap++;
	return (overlap);
}

static void	find_mask(t_stack *a, t_stack *b, t_select *mov, t_select *mask)
{
	ft_bzero(mask, sizeof(t_select));
	if (mov->a_up > (stack_len(a) / 2))
		mask->a_down = stack_len(a) - mov->a_up;
	else
		mask->a_up = mov->a_up;
	if (mov->b_up > (stack_len(b) / 2))
		mask->b_down = stack_len(b) - mov->b_up;
	else
		mask->b_up = mov->b_up;
	mask->overlap = find_overlap(*mask);
}

static void	selection2(t_stack *a, t_stack *b, t_select *mov, int len)
{
	t_select	solution;
	t_select	ms;
	t_stack		*p;
	int			sum;

	sum = 2147483647;
	while (len--)
	{
		p = a;
		mov->a_up = 0;
		while (!(b->n < p->n && (b->n > p->prev->n || p->prev->max == 1)))
		{
			(mov->a_up)++;
			p = p->next;
		}
		find_mask(a, b, mov, &ms);
		if ((ms.a_up + ms.a_down + ms.b_up + ms.b_down - ms.overlap) < sum)
		{
			sum = ms.a_up + ms.a_down + ms.b_up + ms.b_down - ms.overlap;
			solution = ms;
		}
		(mov->b_up)++;
		b = b->next;
	}
	*mov = solution;
}

static void	selection3(t_stack **a, t_stack **b, t_select mov)
{
	while (mov.a_up > 0 && mov.b_up > 0)
	{
		rotate_stack(a, "rr");
		rotate_stack(b, 0);
		(mov.a_up)--;
		(mov.b_up)--;
	}
	while ((mov.a_up)--)
		rotate_stack(a, "ra");
	while ((mov.b_up)--)
		rotate_stack(b, "rb");
	while (mov.a_down > 0 && mov.b_down > 0)
	{
		reverse_rotate_stack(a, "rrr");
		reverse_rotate_stack(b, 0);
		(mov.a_down)--;
		(mov.b_down)--;
	}
	while ((mov.a_down)--)
		reverse_rotate_stack(a, "rra");
	while ((mov.b_down)--)
		reverse_rotate_stack(b, "rrb");
	push_stack(b, a, "pa");
}

void	selection(t_stack **a, t_stack **b)
{
	t_select	mov;

	ft_bzero(&mov, sizeof(t_select));
	while ((*b) != 0)
	{
		selection2(*a, *b, &mov, stack_len(*b));
		selection3(a, b, mov);
		ft_bzero(&mov, sizeof(t_select));
	}
}
