/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:37:57 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/27 22:39:44 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <unistd.h>

static int	free_all(t_stack *a, char **operations, int *numbers, char *massage)
{
	(void)numbers;
	empty_stack(a);
	free_buffers(operations);
	//free(numbers);
	ft_putstr_fd(massage, 1);
	return (0);
}

#include <stdio.h>
int checker(int ac, char **av)
{
	char **operations;
	char	*buffer_operations;
	int	*numbers;
	t_stack	a;
	t_stack	b;

	if (ac < 2)
		return (0);
	init_stack(&a);
	numbers = NULL;
	if (!parse_checker(ac, av, &numbers, &a))
		return (0);
	buffer_operations = NULL;
	buffer_operations = read_buffer(0, buffer_operations);
	operations = ft_split(buffer_operations, '\n');
	free(buffer_operations);
	init_stack(&b);
	if (!apply_operations(operations, &a, &b))
		return(free_all(&a, operations, numbers, "KO\n"));
	if (is_sorted(&a) == 1 && apply_operations(operations, &a, &b))
		free_all(&a, operations, numbers, "OK\n");
	else
		return(free_all(&a, operations, numbers, "KO\n"));
	return(1);
}

int	main(int ac, char **av)
{
	if (!checker(ac, av))
		return (1);
	return (0);
}
