/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:26:41 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/22 13:01:02 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stddef.h>

typedef struct s_data {
	int	flag;
	int	bench_mode;
	int	*numbers;
	int	size;
} t_data;

char    **parse(int ac, char **av);
int     error(int ac, char **values, t_data *data);
int     check_duplicate(int *numbers, int size_array);
int     check_flag(int ac, char **values, int *flag_count, t_data *data);
int     check_values(char **values, int start, t_data *data);
void	ft_putstr_fd(char *s, int fd);
size_t  ft_strlen(const char *s);
void	init_data(t_data *data);

#endif
