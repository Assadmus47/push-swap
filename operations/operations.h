/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:43:50 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/16 00:18:00 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		sa(t_stack *stack_a);
int		sb(t_stack *stack_b);
int		ss(t_stack *stack_a, t_stack *stack_b);
int		pa(t_stack *a, t_stack *b);
int		pb(t_node **stack_b, t_node **stack_a);

#endif