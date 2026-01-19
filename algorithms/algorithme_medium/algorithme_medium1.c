/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme_medium1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:46:59 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/19 20:56:47 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithme_medium.h"

void	mov_to_b(t_stack *a, t_stack *b)
{
	int		current_chunk;
	int		max_index;
	int		chunk_size;
	t_node	*tmp;
	int		i;

	tmp = a->top;
	i= 0;
	chunk_size = ft_sqrt(a->size);
	current_chunk = 0;
	max_index = chunk_size;
	while (a->top != NULL)
	{
		while (i < a->size)
		{
			if (a->top->value < max_index)
				pb(a, b);
			ra(a);
			i++;
		}
		max_index += chunk_size;
	}
}

int	algorithme_medium(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	sort_small_stack(a);
	index_stack(a);
	mov_to_b(a, b);
}