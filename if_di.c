#include "ss_printf.h"

int 	ft_putnbr_byte(int n)
{
	int byte;

	byte = 0;
	if (n == -2147483648)
		ft_putstr("-2147483648");
	if (n < 0 && n != -2147483648)
	{
		n = n * -1;
		ft_putchar('-');
		byte++;
	}
	if (n >= 10)
	{
		byte += ft_putnbr_byte(n / 10); // have to byte += for recursion return,
		byte += ft_putnbr_byte(n % 10); // to be included in byte count
	}
	if (n >= 0 && n <= 9)
	{
		ft_putchar(n + 48);
		byte++; 
	}
	//printf("2 this is total byte in putnbr:%d\n", byte );
	return(byte);
}


void	if_d(va_list ap, int ***byte_ct) //make return value int from void
{
	int d;
	//printf("1 this is byte_ct: %i\n", ***byte_ct);
	d = va_arg(ap, int);
	***byte_ct += ft_putnbr_byte(d);
	//printf(" 3 this is total outside byte_ct: %i\n", ***byte_ct);
}

void	if_i(va_list ap, int ***byte_ct) //make return value int from void
{
	int d;

	d = va_arg(ap, int);
	***byte_ct += ft_putnbr_byte(d); //put byte_ct infront of this 'byte_ct = ft_...
}
