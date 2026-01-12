/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:27:48 by hhamidi           #+#    #+#             */
/*   Updated: 2025/12/11 13:06:27 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	if (!s)
		s = "(null)";
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	ft_putnbr(int n)
{
	int		len;
	long	nb;
	char	c;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		len++;
	}
	if (nb >= 10)
		len += ft_putnbr(nb / 10);
	c = nb % 10 + '0';
	write(1, &c, 1);
	return (len + 1);
}

static int	ft_puthex(unsigned long nb)
{
	int		len;
	char	*base;
	char	c;

	base = "0123456789abcdef";
	len = 0;
	if (nb >= 16)
		len += ft_puthex(nb / 16);
	c = base[nb % 16];
	write(1, &c, 1);
	return (len + 1);
}

int	ft_putptr(void *ptr)
{
	int	len;

	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	len = 2;
	write(1, "0x", 2);
	len += ft_puthex((unsigned long)ptr);
	return (len);
}
