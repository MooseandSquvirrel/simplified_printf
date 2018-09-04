#include "ss_printf.h"


int 	octal(unsigned int num)
{
	
	int i;
	int oct;
	int bytes;
	char *octnum;

	i = 1;
	oct = 0;

	while (num != 0)
	{
		oct += (num % 8) * i;
		num /= 8;
		i *= 10;
	}
	octnum = ft_itoa(oct);
	ft_putstr(octnum);
	bytes = ft_strlen(octnum);
	return (bytes);
}

void 	if_o(va_list ap, int ***byte_ct) //make return value int from void
{
	unsigned int o;

	o = va_arg(ap, unsigned int);
	***byte_ct += octal(o);
}
