/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 23:19:51 by agardner          #+#    #+#             */
/*   Updated: 2018/05/16 15:26:04 by agardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		totallength;
	const char	*s2;
	char		*d2;

	s2 = src;
	d2 = dst;
	i = 0;
	totallength = ft_strlen(dst) + ft_strlen(src);
	while (d2[i] && size > 0)
	{
		i++;
		size--;
	}
	if (size == 0)
		return (i + ft_strlen(src));
	while (*s2 && size > 1)
	{
		d2[i] = *s2;
		size--;
		s2++;
		i++;
	}
	d2[i] = '\0';
	return (totallength);
}
