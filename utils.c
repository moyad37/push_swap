#include "push_swap.h"

int	ft_is_number(char *n)
{
	int	i;

	i = 0;
	if (n[i] == '-')
		i++;
	while (n[i++])
		if (!ft_isdigit(n[i]))
			return (1);
	return (0);
}

long	ft_atol(const char *str)
{
	int sign = 1;
	long result = 0;
	int i = 0;

	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			sign = -1;
		}
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}