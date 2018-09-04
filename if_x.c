#include "ss_printf.h"

int 	hex_byte(unsigned int n)
{
	int i;
	char *s;
	char *tmp;

	tmp = malloc(9); // 8 hex characters is max amount because int is 4bytes.
	ft_memset(tmp, '\0', 9);
	i = 0;
	while (n)
	{
		s = "0123456789abcdef";
		tmp[i] = s[(n % 16)];
		n = n / 16;
		i++;
	}
	ft_putstr(ft_strrev(tmp));
	free(tmp);
	return(i);
}

void	if_x(va_list ap, int ***byte_ct)
{
	unsigned int x;

	x = va_arg(ap, unsigned int);
	***byte_ct += hex_byte(x);
}
