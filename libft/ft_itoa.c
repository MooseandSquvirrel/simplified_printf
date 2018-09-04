/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 19:39:25 by agardner          #+#    #+#             */
/*   Updated: 2018/05/16 14:45:50 by agardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*s;
	int		strlen;
	long	num;

	num = (long)n;
	strlen = ft_digitcounter(n);
	if (!(s = (char*)malloc(sizeof(char) * strlen + 1)))
		return (NULL);
	s[strlen--] = '\0';
	if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		s[0] = '-';
		num = num * -1;
	}
	while (num > 0)
	{
		s[strlen--] = (num % 10) + '0';
		num = num / 10;
	}
	return (s);
}
