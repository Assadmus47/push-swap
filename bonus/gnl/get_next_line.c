/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamidi <hhamidi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:08:20 by hhamidi           #+#    #+#             */
/*   Updated: 2026/01/05 16:34:30 by hhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen_n(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\n' && s[len] != '\0')
		len++;
	if (s[len] == '\n')
		len++;
	return (len);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_src;

	i = 0;
	len_src = ft_strlen(src);
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len_src);
}

static void	*ft_free_return(void *ptr1, void *ptr2)
{
	free(ptr1);
	free(ptr2);
	return (NULL);
}

static char	*ft_read(int fd, char *read_str)
{
	char	*buffer;
	ssize_t	bytes;
	char	*tmp;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (ft_free_return(read_str, NULL));
	while (!ft_strchr(read_str, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == 0)
			break ;
		else if (bytes == -1)
			return (ft_free_return(read_str, buffer));
		buffer[bytes] = '\0';
		tmp = read_str;
		read_str = ft_strjoin(tmp, buffer);
		free(tmp);
		if (!read_str)
			return (ft_free_return(buffer, NULL));
	}
	free(buffer);
	return (read_str);
}

char	*get_next_line(int fd)
{
	static char	storage[BUFFER_SIZE + 1];
	char		*read_str;
	char		*line;
	size_t		len;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		storage[0] = '\0';
		return (NULL);
	}
	read_str = ft_strdup(storage);
	storage[0] = '\0';
	if (!read_str)
		return (NULL);
	read_str = ft_read(fd, read_str);
	if (!read_str)
		return (NULL);
	len = ft_strlen_n(read_str);
	line = ft_substr(read_str, 0, len);
	if (!line)
		return (ft_free_return(read_str, NULL));
	ft_strlcpy(storage, read_str + len, ft_strlen(read_str + len) + 1);
	free(read_str);
	return (line);
}
