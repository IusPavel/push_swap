#include "push_swap.h"

void	throw_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static int	ft_checknum(const char *str)
{
	int		i;
	ssize_t	result;
	int		sign;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	if (str[i] == 0)
		throw_error();
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			throw_error();
		result = (result * 10) + str[i] - '0';
		i++;
	}
	result *= sign;
	if (ft_strlen(str) > 11 || result > 2147483647 || result < -2147483648)
		throw_error();
	return ((int)result);
}

int	mastoi(int **result, char **arguments)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (arguments[i] != 0)
		i++;
	*result = (int *)malloc(sizeof(int) * i);
	while (arguments[k] != 0)
	{
		(*result)[k] = ft_checknum(arguments[k]);
		free(arguments[k]);
		k++;
	}
	free(arguments[k]);
	free(arguments);
	arguments = 0;
	return (i);
}

void	check_stack(int len, int *numbers)
{
	int	i;
	int	k;

	i = 0;
	while (i < len)
	{
		k = i + 1;
		while (k < len)
		{
			if (numbers[i] == numbers[k])
				throw_error();
			k++;
		}
		i++;
	}
	if (len < 1)
		exit(EXIT_SUCCESS);
}
