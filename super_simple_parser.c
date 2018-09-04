#include "ss_printf.h"

void 	parser(char *str, va_list ap, int **byte_ct)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
			{
				ft_putchar(str[i]);
				**byte_ct +=1;
			}
			if (str[i + 1] == 's')
				//printf("byte val test %i\n", *byte_ct[0]);
				if_s(ap, &byte_ct);
			else if (str[i + 1] == 'd')
				if_d(ap, &byte_ct);
			else if (str[i + 1] == 'o')
				if_o(ap, &byte_ct);
			else if (str[i + 1] == 'c')
				if_c(ap, &byte_ct);
			else if (str[i + 1] == 'i')
				if_i(ap, &byte_ct);
			else if (str[i + 1] == 'u')
				if_u(ap, &byte_ct, &str); //needs '&' of string to reference the '-' sign in function
			else if (str[i + 1] == 'p')
				if_p(ap, &byte_ct); 
			else if (str[i + 1] == 'x')
				if_x(ap, &byte_ct);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			**byte_ct += 1;
		}
		i++;
	}

}

/*
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
	printf("this is byte_ct: %i\n", ***byte_ct);
	***byte_ct += putstr_byte(s); //put byte_ct infront of this 'byte_ct = ft_...
	printf("\nthis is byte_ct after: %i\n", ***byte_ct);

}

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

void	if_i(va_list ap, int ***byte_ct) //make return value int from void
{
	int d;

	d = va_arg(ap, int);
	***byte_ct += ft_putnbr_byte(d); //put byte_ct infront of this 'byte_ct = ft_...
}

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


	int array[2147483647];
	int i;
	int len;

	i = 0;
	len = 0;
	while (num > 0)
	{
		array[i] = num % 8;
		num = num / 8;
		i++;
		len++;
	}
	while ((len - 1) > 0)
	{
		ft_putnbr(array[i--]);
		len--;
	}
}

	//char *str;
	//int i;

	//i = 0;
	//str = malloc(5);

	if (num >= 8)
	{
		octal(num % 8);
		octal(num / 8);
	}
	if (num > 0 && num <= 9)
	{
		ft_putchar(num + 48);
		//str[i] = num + 48;
		//i++;
	}
	//ft_putstr(ft_strrev(str));

	//free(str);
	//return();
}


void 	if_o(va_list ap, int ***byte_ct) //make return value int from void
{
	unsigned int o;

	o = va_arg(ap, unsigned int);
	***byte_ct += octal(o);
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
*/
