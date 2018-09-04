#include "ss_printf.h"

int 	putstr_byte(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]); // monkey came at the front of sentence when used ft_putstr  
		i++;
	}
	return(i);
}

void		if_s(va_list ap, int ***byte_ct) //make return value int from void
{
	char *s;
	
	s = va_arg(ap, char *);
	//printf("this is byte_ct: %i\n", ***byte_ct);
	***byte_ct += putstr_byte(s); //put byte_ct infront of this 'byte_ct = ft_...
	//printf("\nthis is byte_ct after: %i\n", ***byte_ct);

}

