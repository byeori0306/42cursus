int	ft_is_specifier(char c)
{
	char *specifier;

	specifier = "cspdiuxX%";
	while (*specifier)
	{
		if (*specifier == c)
			return (1);
		specifier++;
	}
	return (0);
}

int	ft_is_flag(char c)
{
	return (c == '.' || c == '*' || c == '0' || c == '-');
}
