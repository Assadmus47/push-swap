/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:26:41 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/19 18:14:32 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stddef.h>
char    **parse(int ac, char **av);
int     error(int ac, char **values, int **numbers);
int     check_duplicate(int *numbers, int size_array);
int     check_flag(int ac, char **values, int *flag_count);
int     check_values(char **values, int flag_count, int **numbers_array, int size_array);
void	ft_putstr_fd(char *s, int fd);
size_t  ft_strlen(const char *s);

#endif
