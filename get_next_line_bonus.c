/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbernard <wbernard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:15:49 by wbernard          #+#    #+#             */
/*   Updated: 2022/01/10 13:14:28 by wbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_get_string(char **rest)
{
	char	*end_of_line;
	char	*result;
	char	*temp;

	if (!*rest)
		return (NULL);
	if (!**rest)
	{
		free(*rest);
		return (NULL);
	}
	end_of_line = ft_strchr(*rest, '\n');
	if (!end_of_line)
	{
		result = ft_substr(*rest, 0, ft_strlen(*rest));
		free(*rest);
		*rest = NULL;
		return (result);
	}
	result = ft_substr(*rest, 0, (end_of_line - *rest + 1));
	temp = *rest;
	*rest = ft_substr(end_of_line + 1, 0, ft_strlen(end_of_line + 1));
	free(temp);
	return (result);
}

static	char	*ft_read(int fd, char **rest, char *buffer)
{
	int		bytes_count;
	char	*temp;

	if (!*rest || !(ft_strchr(*rest, '\n')))
	{
		bytes_count = read(fd, buffer, BUFFER_SIZE);
		while (bytes_count)
		{
			buffer[bytes_count] = 0;
			if (!*rest)
				*rest = ft_substr(buffer, 0, bytes_count);
			else
			{
				temp = *rest;
				*rest = ft_strjoin(*rest, buffer);
				free(temp);
			}
			if (ft_strchr(buffer, '\n'))
				break ;
			bytes_count = read(fd, buffer, BUFFER_SIZE);
		}
	}
	return (*rest);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*rest[OPEN_MAX];
	char		*result;

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	ft_read(fd, &rest[fd], buffer);
	result = ft_get_string(&rest[fd]);
	return (result);
}
