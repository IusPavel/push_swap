#include "push_swap.h"

static int	str_parser(int argc, char **argv)
{
	int		result;
	char	**temp;
	int		i;

	result = 0;
	while (argc-- > 1)
	{
		i = 0;
		temp = ft_split(*(++argv), ' ');
		if (!temp)
			exit(EXIT_FAILURE);
		while (temp[i] != 0)
		{
			result++;
			free(temp[i]);
			i++;
		}
		free(temp);
	}
	return (result);
}

char	**argv_parser(int argc, char **argv)
{
	char	**arguments;
	char	**temp;
	int		i;
	int		k;

	i = 0;
	k = 0;
	arguments = (char **)malloc(sizeof(char *) * (str_parser(argc, argv) + 1));
	if (!arguments)
		exit(EXIT_FAILURE);
	while (argc-- > 1)
	{
		i = 0;
		temp = ft_split(*(++argv), ' ');
		if (!temp)
			exit(EXIT_FAILURE);
		while (temp[i] != 0)
			arguments[k++] = temp[i++];
		free(temp);
	}
	arguments[k] = 0;
	return (arguments);
}
