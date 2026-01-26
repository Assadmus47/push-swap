/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:44:50 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/26 19:45:36 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	parse_checker(int ac, char **av, int *numbers)
{
	char *values;

	if (ac < 2 || !validate_arguments(ac, av))
		return (0);
	values = join_and_split_args(ac, av);
	if (!values)
		return (0);
	if (!validate_input(values))
	{
		free_buffers(values);
		return (0);
	}
	free_buffers(values);
	free(numbers);
	return (1);
}

