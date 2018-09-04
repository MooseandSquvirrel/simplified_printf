/* 42 Header */

#include "libft.h"

char *ft_strrev(char *str)
{
	int i;
	int j;
	char k;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		k = str[j];
		str[j] = str[i];
		str[i] = k;
		i++;
		j--;
	}
	return(str);
}
