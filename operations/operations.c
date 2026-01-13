/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:33:20 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/13 19:09:40 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

int	sa(t_node **stack_a)
{
	t_node *tmp;
	
	if (!*stack_a || !(*stack_a)->next)
		return (0);
	tmp = *stack_a;
	*stack_a = tmp->next;
	tmp->next = (*stack_a)->next;
	(*stack_a)->next = tmp;
	return (1);
}

int	saa(t_stack *s)
{
	t_node *ex_top;
	t_node *tmp2;
	
	if (!s->top || s->size < 2)
		return (0);
	ex_top = s->top;
	tmp2 =(s->top)->next;
	(s->top) = (s->top)->next;
	(s->top)->prev = ex_top->prev;

}

int	sb(t_node **stack_b)
{
	t_node *tmp;
	
	if (!*stack_b || !(*stack_b)->next)
		return (0);
	tmp = *stack_b;
	*stack_b = tmp->next;
	tmp->next = (*stack_b)->next;
	(*stack_b)->next = tmp;
	return (1);
}

int	ss(t_node **stack_a, t_node **stack_b)
{
	int	result_a;
	int	result_b;

	result_a = sa(stack_a);
	result_b = sb(stack_b);
	
	return (result_a && result_b);
}

int	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp_a;

	if (!*stack_b)
		return (0);
	tmp_a = *stack_a;
	*stack_a = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_a)->next = tmp_a;
	return (1);
}

int	pb(t_node **stack_b, t_node **stack_a)
{
	t_node	*tmp_a;

	if (!*stack_a)
		return (0);
	tmp_a = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = tmp_a;
	return (1);
}

int	main(void)
{
	t_node	*stack;

	push(&stack, 10);
	push(&stack, 20);
	push(&stack, 30);
	printf("before calling sa %d \n", peek(stack));
	sa(&stack);
	printf("after calling sa %d \n", peek(stack));
	printf("pop the peek %d \n",pop(&stack));
	printf("after poping sa %d \n", peek(stack));
	printf("pop the peek %d \n",pop(&stack));
	printf("after poping sa %d \n", peek(stack));
	free(stack);
}

