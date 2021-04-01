#include "../ft_printf.h"

int	ft_putstr(char *s)
{
	int i;
	
	i = 0;
	while(s[i] != '\0')
		i += ft_putchar(s[i]);

	return (i);
}
