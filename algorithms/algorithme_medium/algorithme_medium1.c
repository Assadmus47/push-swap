/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme_medium1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:46:59 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/19 20:19:27 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithme_medium.h"

void	mov_to_b(t_stack *a, t_stack *b)
{
	int		current_chunk;
	int		max_index;
	int		chunk_size;
	t_node	*tmp;

	tmp = a->top;
	chunk_size = ft_sqrt(a->size);
	current_chunk = 0;
	max_index = chunk_size;
	while (current_chunk < a->size)
	{
		if (tmp->value < max_index)
		{
			pb(a, b);
			current_chunk++;
		}
		if (current_chunk == max_index)
			max_index += chunk_size;
		tmp = tmp->next;
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