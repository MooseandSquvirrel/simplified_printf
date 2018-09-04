#include "ss_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list ap;
	//int byte_ct;
	//int total;
	int *byte_ct;

	//byte_ct = 0;
	byte_ct = (int*)malloc(sizeof(int) * 1);
	*byte_ct = 0; //tried to protect with (!(byte_ct = etc etc return (NULL) but printf returns int not int*))
	va_start(ap, str);
	parser((char *)str, ap, &byte_ct); /* make it:--> tots = parser(etc etc etc) when byte count */
	va_end(ap);
	return (*byte_ct);
}