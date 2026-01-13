/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_stack_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:12:58 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/13 18:26:09 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

t_node *new_node(int value)
{
    t_node *n;

	n = malloc(sizeof(t_node));
    if (!n)
        return (NULL);
    n->value = value;
    n->next = n;
    n->prev = n;
    return (n);
}
int	push(t_stack *s, int value)
{
	t_node	*n;
	t_node	*last;

	n = new_node(value);
	if (!n)
		return (0);
	if (!s->top)
		s->top = n;
	else
	{
		// recuperer le previous
		last = (s->top)->prev;
		// modifie le next et le prev
		n->next = s->top;
		n->prev = last;
		// modif le premier elemant
		last->next = n;
		// modif le previous de l'ancien top
		(s->top)->prev = n;
		// definir le top
		s->top = n;
	}
	s-;
}

int	pop(t_node **stack)
{
	t_node *tmp;
	int		value;
	
	if (!*stack)
		return (0);
	tmp = *stack;
	value = tmp->value;
	*stack = tmp->next;
	free(tmp);
	return (value);
}

int	peek(t_node *stack)
{
	if (!stack)
		return (0);
	return (stack->value);
}