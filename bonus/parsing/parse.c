/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:44:50 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/27 21:44:40 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	free_buffers(char **tab)
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

static int	validate_arguments(int ac, char **av)
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

static int	fill_stack(t_stack *stack, int *numbers, int size)
{
	int	i;

	i = size - 1;
	while (i >= 0)
	{
		if (!push(stack, numbers[i]))
			return (empty_stack(stack));
		i--;
	}
	return (1);
}

int	empty_stack(t_stack *stack)
{
	while (stack->size > 0)
		pop(stack);
	return (0);
}

int	parse_checker(int ac, char **av, int **numbers, t_stack *stack)
{
	char **values;
	int	numbers_size;

	if (ac < 2 || !validate_arguments(ac, av))
		return (0);
	values = join_and_split_args(ac, av);
	if (!values)
		return (0);
	numbers_size = 0;
	if (!validate_input(values, numbers, &numbers_size))
	{
		free_buffers(values);
		return (0);
	}
	if (!fill_stack(stack, *numbers, numbers_size))
	{
		free_buffers(values);
		free(*numbers);
		return (0);
	}
	free_buffers(values);
	free(*numbers);
	return (1);
}

