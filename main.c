/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:28:20 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/16 19:01:56 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
// Simple min/max extraction methods

void afficher_stack_debug(t_stack *stack)
{
	int		i;
	t_node	*current;

	if (!stack || !stack->top)
	{
		printf("Stack vide\n");
		return ;
	}
	
	printf("=== Stack (size = %d) ===\n", stack->size);
	i = 1;  // Position commence à 1
	current = stack->top;
	while (i <= stack->size)
	{
		printf("Position %d: value = %d, next = %p, prev = %p\n", 
			i, current->value, (void *)current->next, (void *)current->prev);
		current = current->next;
		i++;
	}
	printf("========================\n");
}

int	main(void)
{
	t_stack a;
	t_stack b;
	
	init_stack(&a);
	init_stack(&b);
	push(&a, 1);
	push(&a, 5);
	push(&a, 2);
	push(&a, 9);
	printf("avant algo : \n");
	afficher_stack_debug(&a);
	algorithme_simple(&a, &b);
	printf("apres algo : \n");
	afficher_stack_debug(&a);
}