/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 16:39:20 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/18 17:40:28 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int is_sorted(t_stack *a)
{
	t_node *tmp;

	if (!a || !a->top)
		return (1);
	if (a->top->next == a->top)
		return (1);

	tmp = a->top;
	while (tmp->next != a->top)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
