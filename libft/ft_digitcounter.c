/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitcounter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 14:53:08 by agardner          #+#    #+#             */
/*   Updated: 2018/05/16 14:43:32 by agardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_digitcounter(int n)
{
	int		count;
	long	nb;

	nb = (long)n;
	count = 0;
	if (nb == 0)
		return (count++);
	if (nb < 0)
	{
		count++;
		nb = nb * -1;
	}
	while (nb > 0)
	{
		count++;
		nb = nb / 10;
	}
	return (count);
}
