#include "../ft_printf.h"

char	*ft_is_specifier(char c)
{
	char *spec;

	spec = "cspdiuxX%";
	while (*spec)
	{
		if (*spec == c)
			return (1);
		spec++;
	}
	return (0);
	//return (ft_strchr("cspdiuxX%", c));
}

char	*ft_is_option(char c)
{
	return (ft_strchr("-0.", c));
}

char	*ft_is_width(char c)
{
	return (ft_strchr("123456789*", c));
}
