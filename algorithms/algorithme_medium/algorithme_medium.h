/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme_medium.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 23:58:20 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/21 23:58:34 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHME_MEDIUM_H
# define ALGORITHME_MEDIUM_H

# include "../../stack/stack.h"
# include "../../operations/operations.h"

# include "../algorithm_simple/algorithme_simple.h"

int		*index_stack(t_stack *a);
void	sort_small_stack(t_stack *a);
int		ft_sqrt(int nb);
int		algorithme_medium(t_stack *a, t_stack *b);
void	real_stack(t_stack *a, int *arr);

#endif