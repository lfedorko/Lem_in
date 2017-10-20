#include "libft.h"

int		convert(char c, int base)
{
	int		i;

	i = base;
	if (c >= '0' && c <= '9')
		i = c - '0';
	if (c >= 'a' && c <= 'f')
		i = c - 'a' + 10;
	if (c >= 'A' && c <= 'F')
		i = c - 'A' + 10;
	if (i < base)
		return (i);
	return (-1);
}


int ft_atoi_base(const char *str, int base)
{
	int		minus;
	int		result;

	result = 0;
	minus = 1;
	if (*str == '-')
	{
		minus = minus * -1;
		++str;
	}
	while (convert(*str, base) != -1)
	{
		result = result * base + convert(*str, base);
		++str;
	}
	return (result * minus);
}

