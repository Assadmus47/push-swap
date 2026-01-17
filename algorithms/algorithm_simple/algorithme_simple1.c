/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme_simple1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 22:11:00 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/16 23:30:02 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithme_simple.h"

// static void	use_ra(t_stack *a, t_stack *b, int value)
// {
// 	while ((a->top)->value != value)
// 	{
// 		write(1, "ra\n", 3);
// 		ra(a);
// 	}
// 	write(1, "pb\n", 3);
// 	pb(b, a);
// }

// static void	use_rra(t_stack *a, t_stack *b, int value)
// {
// 	while ((a->top)->value != value)
// 	{
// 		write(1, "rra\n", 4);
//         rra(a);
// 	}
// 	write(1, "pb\n", 3);
//     pb(b, a);
// }

// static void	mov_to_b(t_stack *a, t_stack *b, int min, int max)
// {
// 	int cost_min;
//     int cost_max;
// 	int pos_min;
// 	int pos_max;

// 	pos_min = position(min, a);
// 	pos_max = position(max, a);
// 	cost_min = cost(pos_min, a->size);
//     cost_max = cost(pos_max, a->size);
// 	if (cost_min <= cost_max)
//     {
// 		if (pos_min <= (a->size / 2 + 1))
// 			use_ra(a, b, min,);
// 		else
// 			use_rra(a, b, min,);
// 	}
//     else
// 	{
//     	if (pos_max <= (a->size / 2 + 1))
// 			use_ra(a, b, max );
// 		else
// 			use_rra(a, b, max);
//     }
// }

// int algorithme_simple(t_stack *a, t_stack *b)
// {
//     int min;
//     int max;

//     while (a->top != NULL)
//     {
//         min = valeur_min(a);
//         max = valeur_max(a);
//         mov_to_b(a, b, min, max);
// 		i++;
//     }
//     while (b->top != NULL)
//     {
//         write(1, "pa\n", 3);
//         if (pa(a, b) == 0)
//             return (0);
//     }
//     min = valeur_min(a);
// 	while (((a->top)->value != min))
// 	{
// 		write(1, "re\n", 3);
// 		ra(a);
// 	}
//     return (1);
// }

// Fonction pour trier 3 éléments dans a
static void	sort_three(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	if (a->size != 3)
		return ;
	top = a->top->value;
	mid = a->top->next->value;
	bot = a->top->prev->value;
	if (top > mid && mid < bot && top < bot)
	{
		write(1, "sa\n", 3);
		sa(a);
	}
	else if (top > mid && mid > bot)
	{
		write(1, "sa\n", 3);
		sa(a);
		write(1, "rra\n", 4);
		rra(a);
	}
	else if (top > mid && mid < bot && top > bot)
	{
		write(1, "ra\n", 3);
		ra(a);
	}
	else if (top < mid && mid > bot && top < bot)
	{
		write(1, "sa\n", 3);
		sa(a);
		write(1, "ra\n", 3);
		ra(a);
	}
	else if (top < mid && mid > bot && top > bot)
	{
		write(1, "rra\n", 4);
		rra(a);
	}
}

static void	use_ra(t_stack *a, t_stack *b, int value)
{
	while ((a->top)->value != value)
	{
		write(1, "ra\n", 3);
		ra(a);
	}
	write(1, "pb\n", 3);
	pb(b, a);
}

static void	use_rra(t_stack *a, t_stack *b, int value)
{
	while ((a->top)->value != value)
	{
		write(1, "rra\n", 4);
		rra(a);
	}
	write(1, "pb\n", 3);
	pb(b, a);
}

static void	push_min_to_b(t_stack *a, t_stack *b)
{
	int	min;
	int	pos_min;
	int	cost_min;

	min = valeur_min(a);
	pos_min = position(min, a);
	cost_min = cost(pos_min, a->size);
	if (pos_min <= a->size / 2)
		use_ra(a, b, min);
	else
		use_rra(a, b, min);
}

int	algorithme_simple(t_stack *a, t_stack *b)
{
	// Étape 1 : Pousser tout vers b sauf 3 éléments
	while (a->size > 3)
		push_min_to_b(a, b);
	
	// Étape 2 : Trier les 3 derniers éléments
	sort_three(a);
	
	// Étape 3 : Tout remettre de b vers a
	while (b->top != NULL)
	{
		write(1, "pa\n", 3);
		if (pa(a, b) == 0)
			return (0);
	}
	
	return (1);
}
