/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 23:15:32 by agardner          #+#    #+#             */
/*   Updated: 2018/05/16 15:04:45 by agardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	*location;
	size_t			i;

	str = (unsigned char *)s;
	location = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == ((unsigned char)c))
		{
			location = str + i;
			return ((void *)location);
		}
		i++;
	}
	return (NULL);
}
