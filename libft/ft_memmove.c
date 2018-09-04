/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 17:21:31 by agardner          #+#    #+#             */
/*   Updated: 2018/05/16 16:49:09 by agardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*strd;
	unsigned char	*strs;
	size_t			i;

	strd = (unsigned char*)dst;
	strs = (unsigned char*)src;
	i = 0;
	if (strs > strd)
	{
		while (i < len)
		{
			strd[i] = strs[i];
			i++;
		}
	}
	else
	{
		while (len > 0)
		{
			len--;
			strd[len] = strs[len];
		}
	}
	return (dst);
}
