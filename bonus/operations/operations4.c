/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 17:46:42 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/26 19:50:39 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	rra(t_stack *a)
{
	if (a->size > 1)
		a->top = a->top->prev;
}

void	rrb(t_stack *b)
{
	if (b->size > 1)
		b->top = b->top->prev;
}

void	rrr(t_stack *a, t_stack *b)
{
	rrb(b, flage);
	rra(a, flage);
}
