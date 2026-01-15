/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:17:19 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/15 22:03:54 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

long	ft_atol(const char *str)
{
	size_t	i;
	int		sign;
	long		result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
//je peux découper cette fonction (une fonction qui check les valeurs, les limits, les doublons)
int	ft_check_values(char **values, int flag_count)
{
	size_t	i;
	long	value_long;
	int	value_int;

	i = flag_count;
	while (values[i])
	{
		if (!ft_isdigit(values[i]))
			return (1);
		value_long = ft_atol(values[i]);
		if (value_long < -2147483648 && value_long > 2147483647)
			return (1);
		value_int = value_long;
		i++;
	}
}
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_atoi("111111111"));
	printf("%d\n", ft_atoi("-111111111"));
	printf("%d\n", ft_atoi("+111111111"));
	printf("%d\n", ft_atoi("--111111111"));
	printf("%d\n", ft_atoi("++111111111"));

	printf("%d\n", ft_atoi("test"));
	return (0);
}

