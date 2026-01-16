/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme_simple1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 22:11:00 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/16 00:32:40 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack/stack.h"
#include "../operations/operations.h"

int cost(int index, int size)
{
    if (index <= size / 2)
        return index;
    else
        return size - index;
}

int valeur_min(t_stack *stack)
{
    int     min;
    int     i;
    t_node  *current;

    i = 1;
    current = stack->top;
    min = current->value;
    while (i <= stack->size)
    {
        if (current->value < min)
            min = current->value;
        current = current->next;
        i++;
    }
    return (min);
}

int valeur_max(t_stack *stack)
{
    int     max;
    int     i;
    t_node  *current;

    i = 1;
    current = stack->top;
    max = current->value;
    while (i <= stack->size)
    {
        if (current->value > max)
            max = current->value;
        current = current->next;
        i++;
    }
    return (max);
}

int position(int value, t_stack *stack)
{
    int     i;
    t_node  *current;

    i = 1;
    current = stack->top;
    while (i <= stack->size)
    {
        if (current->value == value)
            return (i);
        current = current->next;
        i++;
    }
    return (-1);
}

// Simple min/max extraction methods
int algorithme_simple(t_stack *a, t_stack *b)
{
    int min;
    int max;
    int cost_min;
    int cost_max;

    while (a->top != NULL)
    {
        min = valeur_min(a);
        max = valeur_max(a);
        cost_min = cost(position(min, a), a->size);
        cost_max = cost(position(max, a), a->size);
        if (cost_min <= cost_max)
        {
            while ((a->top)->value != min)
            {
                write(1, "ra\n", 3);
                if(ra(a) == 0)
                    return (0);
            }
            write(1, "pb\n", 3);
            if (pb(b, a) == 0)
                return (0);
        }
        else
        {
            while ((a->top)->value != max)
            {
                write(1, "ra\n", 3);
                if(ra(a) == 0)
                    return (0);
            }
            write(1, "pb\n", 3);
            if (pb(b, a) == 0)
                return (0);
        }
    }
    while (b->top != NULL)
    {
        write(1, "pa\n", 3);
        if (pa(a, b) == 0)
            return (0);
    }
    return (1);
}