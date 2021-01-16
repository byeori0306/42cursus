#include <stddef.h>

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

int	get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif
