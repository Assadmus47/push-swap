/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 22:33:15 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/27 22:51:26 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <unistd.h>

static void	*ft_free_return(void *ptr1, void *ptr2)
{
	free(ptr1);
	free(ptr2);
	return (NULL);
}

char	*read_buffer(int fd, char *buffer_operations)
{
	char	*buffer;
	ssize_t	bytes;
	char	*tmp;

	bytes = 1;
	buffer = malloc((1024 + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (bytes > 0)
	{
		bytes = read(fd, buffer, 1024);
		if (bytes == -1)
			return (ft_free_return(buffer, NULL));
		buffer[bytes] = '\0';
		if (!buffer_operations)
			buffer_operations = ft_strdup(buffer);
		else
		{
			tmp = buffer_operations;
			buffer_operations = ft_strjoin(tmp, buffer);
			free(tmp);
		}
		if (!buffer_operations)
			return (ft_free_return(buffer, NULL));
	}
	free(buffer);
	return (buffer_operations);
}
