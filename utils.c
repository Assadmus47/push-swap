/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:14:42 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/22 10:31:24 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_data(t_data *data)
{
	data->flag = 4;
	data->bench_mode = 0;
	data->numbers = NULL;
	data->size = 0;
}


