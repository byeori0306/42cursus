#include "../ft_printf.h"
#include <stdlib.h>

int		ft_get_hex_len(unsigned long long num)
{
	int cnt;

	cnt = 0;
	while (num > 0)
	{
		num /= 16;
		cnt++;
	}
	return (cnt);
}

char	*ft_convert_hex(unsigned long long num, int letter_case)
{
	char *str;
	char *base;
	int len;
	int i;

	if (num == 0)
		return (ft_strdup("0"));
	if (letter_case == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	i = 0;
	len = ft_get_hex_len(num);
	if (!(str = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (num > 0)
	{
		str[len - ++i] = base[num % 16];
		num /= 16;
	}
	str[len] = '\0';
	return (str);
}
