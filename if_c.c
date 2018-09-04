#include "ss_printf.h"

int		ft_putchar_byte(char b)
{
	int i;

	i = 1;
	write(1, &b, 1);
	return(i); // or just return 1 ....?
}

void	if_c(va_list ap, int ***byte_ct) //make return value int from void
{
	char b;

	b = va_arg(ap, int); 
	***byte_ct += ft_putchar_byte(b); //put byte_ct infront of this 'byte_ct = ft_...'
}

