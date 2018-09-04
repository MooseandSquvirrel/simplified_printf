/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 23:14:52 by agardner          #+#    #+#             */
/*   Updated: 2018/05/16 15:02:17 by agardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*strd;
	unsigned char	*strs;
	size_t			i;

	strd = (unsigned char *)dst;
	strs = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*strd = *strs;
		if (((unsigned char)c) == *strs)
		{
			strd++;
			return (strd);
		}
		strs++;
		strd++;
		i++;
	}
	return (NULL);
}
