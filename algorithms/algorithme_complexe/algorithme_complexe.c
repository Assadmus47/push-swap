/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme_complexe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:07:58 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/20 22:21:53 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithme_complexe.h"

static void	mov_to_b(t_stack *a, t_stack *b)
{
	int	bit;
	int	bit_max;
	int	i;
	int	size;

	bit = 0;
	bit_max = 0;
	while (((a->size - 1) >> bit_max) != 0)
		bit_max++;
	while (bit < bit_max)
	{
		i = 0;
		size = a->size;
		while (i < size)
		{
			if (((a->top->value >> bit) & 1) == 0)
				pb(b, a);
			else
				ra(a);
			i++;
		}
		while (b->size > 0)
			pa(a, b);
		bit++;
	}
}

int	algorithme_complexe(t_stack *a, t_stack *b)
{
	int		*arr;

	if (is_sorted(a))
		return (0);
	arr = index_stack(a);
	mov_to_b(a, b);
	real_stack(a, arr);
	free(arr);
	return (1);
}
