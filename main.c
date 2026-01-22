/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 19:51:40 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/22 13:01:03 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>
static void	free_buffers(char **tab)
{
	size_t	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static int check_valid_args(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!av[i] || !av[i][0])
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

int	push_swap(int ac, char **av)
{
	t_data	data;
	char	**values;

	if (ac < 2 || !check_valid_args(ac, av))
		return (0);
	values = parse(ac, av);
	if (!values)
		return (0);
	init_data(&data);
	if (!error(ac, values, &data))
	{
		free_buffers(values);
		return (0);
	}
	printf("flag : %d | bench_mode : %d\n", data.flag, data.bench_mode);
	printf("numbers\n");
	for (int i = 0; i < data.size; i++)
	{
		printf("numbers[%d] : %d\n", i,data.numbers[i]);
	}
	printf("size of numbers array : %d\n", data.size);
	free_buffers(values); // for the test
	free(data.numbers); // for the test
	return (1);
}
#include <stdio.h>
int	main(int ac, char **av)
{
	printf("ac = %d\n", ac);
	printf("return %d\n", push_swap(ac, av));
	return (0);
}
