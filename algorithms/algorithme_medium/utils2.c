/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 01:22:53 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/18 17:57:17 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithme_medium.h"

void	sort_small_stack(t_stack *a)
{
	if (a->size == 2)
		sa(a);
}

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		return (0);
	while (i < nb)
	{
		if ((i * i) >= nb)
			return (i);
		i++;
	}
	return (0);
}
