#ifndef PRINTF_H

# define PRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include "./libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

int 		ft_printf(const char *format, ...);
void 		parser(char *str, va_list ap, int **byte_ct);
void		if_s(va_list ap, int ***byte_ct);
void		if_c(va_list ap, int ***byte_ct);
void		if_d(va_list ap, int ***byte_ct);
void		if_i(va_list ap, int ***byte_ct);
void	 	if_o(va_list ap, int ***byte_ct);
void		if_p(va_list ap, int ***byte_ct);
void		if_x(va_list ap, int ***byte_ct);
void		if_u(va_list ap, int ***byte_ct, char **str);
#endif