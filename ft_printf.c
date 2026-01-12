/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi<hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 19:15:14 by hhamidi           #+#    #+#             */
/*   Updated: 2025/12/11 15:41:27 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_parsing(char conversion_specifier, va_list args)
{
	int	len;

	len = 0;
	if (conversion_specifier == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (conversion_specifier == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (conversion_specifier == 'p')
		len += ft_putptr(va_arg(args, void *));
	else if (conversion_specifier == 'd' || conversion_specifier == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (conversion_specifier == 'u')
		len += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (conversion_specifier == 'x')
		len += ft_putnbr_hex(va_arg(args, unsigned int), "0123456789abcdef");
	else if (conversion_specifier == 'X')
		len += ft_putnbr_hex(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (conversion_specifier == '%')
		len += ft_putchar('%');
	else
	{
		len += ft_putchar('%');
		len += ft_putchar(conversion_specifier);
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	if (format == NULL)
		return (-1);
	i = 0;
	va_start(args, format);
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				break ;
			len += ft_parsing(format[i + 1], args);
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
