/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:29:27 by hhamidi           #+#    #+#             */
/*   Updated: 2025/12/10 19:07:07 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_putnbr_hex(unsigned int nbr, char *base)
{
	int		len;
	char	c;

	len = 0;
	if (nbr >= 16)
		len += ft_putnbr_hex(nbr / 16, base);
	c = base[nbr % 16];
	write(1, &c, 1);
	return (len + 1);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int		len;
	long	nb;
	char	c;

	nb = n;
	len = 0;
	if (nb >= 10)
		len += ft_putnbr_unsigned(nb / 10);
	c = nb % 10 + '0';
	write(1, &c, 1);
	return (len + 1);
}
