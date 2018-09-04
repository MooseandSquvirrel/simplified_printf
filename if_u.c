#include "ss_printf.h"

static int 	ft_putnbr_byte(int n) //static  because i used in if_di.c and it sees duplicates when gcc-ing
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

int 	ft_putnbr_unsign_byte(unsigned int n, char ***str)
{
	int byte;
	int i;

	byte = 0;
	i = 0;

	if (**str[i] == '-')        //i don't fully understand why this works 
		n = 4294967295 - n;		// if dealing with unsigned int and not string by referencing
	if (n >= 10)				// the str[i] for '-'
	{
		byte += ft_putnbr_byte(n / 10);
		byte += ft_putnbr_byte(n % 10);
	}
	if (n >= 1 && n <= 9)
	{
		ft_putchar(n + 48);
		byte++; 
	}
	return(byte);
}

void	if_u(va_list ap, int ***byte_ct, char **str)
{
	unsigned int u;

	u = va_arg(ap, unsigned int);
	***byte_ct += ft_putnbr_unsign_byte(u, &str);
}
