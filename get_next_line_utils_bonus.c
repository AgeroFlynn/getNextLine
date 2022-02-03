/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbernard <wbernard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:15:55 by wbernard          #+#    #+#             */
/*   Updated: 2022/01/10 13:12:19 by wbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	const char	*str;

	str = s;
	while (*str++)
		;
	return (str - s - 1);
}

char	*ft_strchr(const char *s, int c)
{
	const char		*src;
	unsigned char	value;

	src = s;
	value = (unsigned char) c;
	while (*src)
	{
		if (*src == value)
			return ((char *) src);
		src++;
	}
	if (value == '\0')
		return ((char *) src);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	char	*work;
	int		result_size;

	if (!s1 || !s2)
		return (NULL);
	result_size = ft_strlen(s1) + ft_strlen(s2);
	result = (char *) malloc (result_size + 1);
	if (!result)
		return (NULL);
	work = result;
	if (s1)
		while (*s1)
			*work++ = *s1++;
	if (s2)
		while (*s2)
			*work++ = *s2++;
	*work = 0;
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	char		*result;
	size_t		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		str = (char *) malloc (sizeof(char));
		*str = 0;
		return (str);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	result = malloc ((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (i < len && s[start])
		result[i++] = s[start++];
	result[i] = 0;
	return (result);
}
