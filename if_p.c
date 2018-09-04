#include "ss_printf.h"

int 	pointer_byte(long n)
{
	long i;
	char *s;
	char *tmp;

	tmp = malloc(15); // 8 hex characters is max amount because int is 4bytes. 15 is max needed for this
	ft_memset(tmp, '\0', 15);
	i = 0;
	ft_putstr("0x");
	while (n)
	{
		s = "0123456789abcdef";
		tmp[i] = s[(n % 16)];
		n = n / 16;
		i++;
	}
	ft_putstr(ft_strrev(tmp));
	free(tmp);
	return(i + 2); // i PLUS 2 because of "0x" ft_putstring line 90-ish
}

void	if_p(va_list ap, int ***byte_ct)
{
	long p;

	p = va_arg(ap, long);
	***byte_ct += pointer_byte(p);
}
