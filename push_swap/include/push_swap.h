#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

char	**argv_parser(int argc, char **argv);
void	throw_error(void);
int		mastoi(int **result, char **arguments);
void	check_stack(int argc, int *argv);
int		ft_strcmp(const char *s1, const char *s2);
typedef struct s_stack
{
	int				n;
	int				max;
	int				to_b;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;
int		is_sorted(t_stack *a);
void	fill_stack(t_stack **lst, int len, int *arguments);
void	sort_stack(t_stack **a, int len);
void	mark_max(t_stack *a);
int		find_max_len(t_stack *a, int len);
int		find_max_len_without_tobe(t_stack *a, int len);
void	push_stack(t_stack **a, t_stack **b, char *text);
void	swap_stack(t_stack **a, char *text);
void	rotate_stack(t_stack **a, char *text);
void	reverse_rotate_stack(t_stack **a, char *text);
void	shift_stack(t_stack **a);
int		stack_len(t_stack *a);
typedef struct s_select
{
	int	overlap;
	int	a_up;
	int	a_down;
	int	b_up;
	int	b_down;
}	t_select;
void	selection(t_stack **a, t_stack **b);

#endif