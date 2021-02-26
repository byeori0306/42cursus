#include <stddef.h>

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

int	get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strdup(const char *s1);

#endif
