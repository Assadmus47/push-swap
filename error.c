/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:24:33 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/15 22:04:10 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	**error(int ac, char **av)
{
	char	**values;
	int	flag_count;

	if (!ft_check_flag(ac, av, &flag_count))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	values = ft_parse(ac, av);
	ft_check_values(values, flag_count);

	
}
