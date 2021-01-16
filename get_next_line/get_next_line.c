#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

char	*gnl_strjoin(char *s1, char *s2)
{
	size_t l1;
	size_t l2;
	size_t len;
	char *result;
	
	if (s1)
		l1 = strlen(s1);
	else
		l1 = 0;
	l2 = strlen(s2);
	len = l1 + l2;
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (s1)
		strncpy(result, s1, l1);
	strncpy(result + l1, s2, l2);
	result[len] = '\0'; // if i use strlcpy i don't have to do this??

	return (result);
}

int	gnl_split(char **storage, char *eol, char **line)
{	
	size_t len;
	
	len = eol - *storage;
	if (!(line[0] = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	strncpy(line[0], *storage, len);
	line[0][len] = '\0';
	*storage = eol + 1;
	//printf("after split storage : %s\n", *storage);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int result;
	char buf[BUFFER_SIZE + 1];
	static char *storage;
	char *eol;
	
	if (storage && (eol = strchr(storage, '\n')))
		return (gnl_split(&storage, eol, line));
	while ((result = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[result] = '\0';
		//printf("before join buf : %s\n", buf);
		storage = gnl_strjoin(storage, buf);
		//printf("after join buf: %s\n", buf);
		if ((eol = (strchr(storage, '\n'))))
		{
			//printf("before split storage : %s\n", storage);
			//printf("eol = %s\n", eol);
			return (gnl_split(&storage, eol, line));
		}
	}
	if (result == 0)
		return (0);
	else
		return (-1);
}

int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *line;
	int result;

	while ((result = get_next_line(fd, &line)) > 0)
		printf("line: %s\n", line);
}
