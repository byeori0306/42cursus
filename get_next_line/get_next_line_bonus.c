/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 03:35:18 by dahpark           #+#    #+#             */
/*   Updated: 2021/02/28 04:26:36 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

char	*gnl_strjoin(char *s1, char *s2)
{
	size_t	l1;
	size_t	l2;
	size_t	len;
	char	*result;

	if (s1)
		l1 = ft_strlen(s1);
	else
		l1 = 0;
	l2 = ft_strlen(s2);
	len = l1 + l2;
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (s1)
	{
		ft_strlcpy(result, s1, l1);
		free(s1);
	}
	ft_strlcpy(result + l1, s2, l2);
	return (result);
}

int		gnl_split(char **storage, char *eol, char **line)
{
	size_t	len;

	len = eol - *storage;
	if (!(*line = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	if (len == 0)
		(*line)[0] = '\0';
	else
		ft_strlcpy(*line, *storage, len);
	ft_memmove(*storage, eol + 1, ft_strlen(*storage) - len);
	return (1);
}

int		gnl_result(ssize_t size, char **storage, char **line)
{
	char	*eol;

	if (size < 0)
		return (-1);
	if (*storage && (eol = (ft_strchr(*storage, '\n'))))
		return (gnl_split(storage, eol, line));
	else if (*storage)
	{
		if (!(*line = ft_strdup(*storage)))
			return (-1);
		free(*storage);
		*storage = NULL;
	}
	else
	{
		if (!(*line = ft_strdup("")))
			return (-1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	ssize_t		size;
	char		*buf;
	static char	*storage[OPEN_MAX];
	char		*eol;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[size] = '\0';
		if (!(storage[fd] = gnl_strjoin(storage[fd], buf)))
			return (-1);
		if ((eol = (ft_strchr(storage[fd], '\n'))))
		{
			free(buf);
			return (gnl_split(&storage[fd], eol, line));
		}
	}
	free(buf);
	return (gnl_result(size, &storage[fd], line));
}
