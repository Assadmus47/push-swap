/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme_medium1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacemi <mkacemi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:46:59 by mkacemi           #+#    #+#             */
/*   Updated: 2026/01/18 17:53:09 by mkacemi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithme_medium.h"

int	algorithme(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	sort_small_stack(a);
	
}