#include <stddef.h>
#include <stdlib.h>
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (0);
}

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	i = 0;
	while (src[i] != '\0' && i + 1 <= dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*temp;
	const unsigned char	*s;

	temp = dst;
	s = src;
	if (dst == NULL && src == NULL)
		return (0);
	if (dst <= src)
	{
		while (len--)
			*temp++ = *s++;
	}
	else
	{
		temp += len;
		s += len;
		while (len--)
			*--temp = *--s;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int	len;
	int	i;

	len = ft_strlen(s1);
	if ((dup = (char *)malloc(sizeof(char) * len + 1)) == NULL)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		dup[i] = s1[i];
		i++;
	}
	dup[len] = '\0';
	return (dup);
}
