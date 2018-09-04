#include "libft.h"

unsigned int	ft_count2delimit(const char *s, char c)
{
	int i;

	i = 0;
	while (*s && *s != c)
	{
		s++;
		i++;
	}
	return (i);
}
