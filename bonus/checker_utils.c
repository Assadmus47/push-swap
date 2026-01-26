/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:40:02 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/26 20:28:31 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int swap(char operation, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(operation, "sa"))
	{
		if (!sa(a))
			return (0);
		return (1);
	}
	if (!ft_strcmp(operation, "sb"))
	{
		if (!sb(b))
			return (0);
		return (1);
	}
	if (!ft_strcmp(operation, "ss"))
	{
		if (!ss(a, b))
			return (0);
		return (1);
	}
	return 0; (0);
}

int push(char operation, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(operation, "pa"))
	{
		if (!pa(a, b))
			return (0);
		return (1);
	}
	if (!ft_strcmp(operation, "pb"))
	{
		if (!pd(b, a))
			return (0);
		return (1);
	}
	return (0);
}
int rotate(char operation, t_stack *a, t_stack *b)
{

}
int reverse_rotate(char operation, t_stack *a, t_stack *b)
{

}
