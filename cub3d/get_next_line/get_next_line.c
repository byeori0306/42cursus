/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 02:57:06 by dahpark           #+#    #+#             */
/*   Updated: 2021/11/16 19:41:02 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

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
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	if (s1)
	{
		ft_strlcpy(result, s1, l1);
		free(s1);
	}
	ft_strlcpy(result + l1, s2, l2);
	return (result);
}

int	gnl_split(char **storage, char *eol, char **line)
{
	size_t	len;

	len = eol - *storage;
	*line = (char *)malloc(sizeof(char) * (len + 1));
	if (!(*line))
		return (-1);
	if (len == 0)
		(*line)[0] = '\0';
	else
		ft_strlcpy(*line, *storage, len);
	ft_memmove(*storage, eol + 1, ft_strlen(*storage) - len);
	return (1);
}

int	gnl_result(ssize_t size, char **storage, char **line)
{
	char	*eol;

	if (size < 0)
		return (-1);
	eol = ft_strchr(*storage, '\n');
	if (*storage && eol)
		return (gnl_split(storage, eol, line));
	else if (*storage)
	{
		*line = ft_strdup(*storage);
		if (!(*line))
			return (-1);
		free(*storage);
		*storage = NULL;
	}
	else
	{
		*line = ft_strdup("");
		if (!(*line))
			return (-1);
	}
	return (0);
}

int	find_next_line(char **storage, char **buf, char **line)
{
	char	*eol;

	eol = ft_strchr(*storage, '\n');
	if (eol)
	{
		free(*buf);
		return (gnl_split(storage, eol, line));
	}
	else
		return (0);
}

int	get_next_line(int fd, char **line)
{
	ssize_t		size;
	char		*buf;
	static char	*storage;

	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE < 1)
		return (-1);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	while (1)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size <= 0)
			break ;
		buf[size] = '\0';
		storage = gnl_strjoin(storage, buf);
		if (!storage)
			return (-1);
		if (find_next_line(&storage, &buf, line))
			return (1);
	}
	free(buf);
	return (gnl_result(size, &storage, line));
}
