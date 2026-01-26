/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:37:57 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/26 20:28:34 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int operations(char **operations, t_stack *a, t_stack *b)
{
	int	operations_count;
	int	i;

	operations_nbr = count_elements(operations);
	i = 0;
	while (i < operations_nbr)
	{
		i++;
	}
}

int checker(int ac, char **av)
{
	char **operations;
	char	*buffer_operations;
	int	*numbers;
	t_stack	a;
	t_stack	b;

	if (!parse_checker(ac, av, &numbers))
		return (0);
	buffer_operations = get_next_line(1);
	operations = ft_split(buffer_operations, '\n');
	init_stack(&a);
	init_stack(&b);
	operations(operations, &a, &b);
}
