#include <unistd.h>

int	ft_putchar(char c)
{
	int cnt;

	cnt = 0;
	write(1, &c, 1);

	return (cnt);
}
