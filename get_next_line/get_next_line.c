#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

char	*gnl_strjoin(char *s1, char *s2)
{
	size_t l1;
	size_t l2;
	size_t len;
	char *result;
	
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

int	gnl_split(char **storage, char *eol, char **line)
{	
	size_t len;
	//size_t length;
	
	len = eol - *storage;
	// printf("line length : %ld\n", len);
	if (!(line[0] = (char *)malloc(sizeof(char) * (len + 2))))
		return (-1);
	ft_strlcpy(line[0], *storage, len);
	//length = ft_strlen(*storage) - len;
	ft_memmove(*storage, eol+1, ft_strlen(*storage)-len);
	// printf("new storage length : %ld\n", length);

	return (1);
}

int	get_next_line(int fd, char **line)
{
	int size;
	int result;
	char *buf;
	static char *storage;
	char *eol;
	
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))	
		return (-1);
	while ((size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[size] = '\0';
		storage = gnl_strjoin(storage, buf); // storage NULL
		if ((ft_strchr(storage, '\n')))
			break;
	}
	free(buf);
	//printf("storage: %s\n", storage);
	if (size < 0)
		return (-1);
	else if (size == 0 && !storage)
		return (0);
	if ((eol = (ft_strchr(storage, '\n'))))
	{
		result = gnl_split(&storage, eol, line);
		if (size >= 0 && size < BUFFER_SIZE)
			result = 0;
		return (result);
	}
	else if (storage)
	{
		*line = ft_strdup(storage);
		free(storage);
		storage = NULL;
	}
	else
		*line = ft_strdup("");
	return (0);
}
