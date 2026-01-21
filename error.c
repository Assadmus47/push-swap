/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:24:33 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/21 20:34:13 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static int count_elements(char **tab)
{
	int	count;

	count = 0;
	while (tab[count])
		count++;
	return (count);
}

int	error(int ac, char **values, t_data *data)
{
	int	flag_count;

	flag_count = 0;
	if (!check_flag(ac, values, &flag_count))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	data->size = count_elements(values) - flag_count;
	data->numbers = malloc(data->size * sizeof(int));
	if (!data->numbers)
		return (0);
	if (!check_values(values, flag_count, data))
	{
		free(data->numbers);
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}
