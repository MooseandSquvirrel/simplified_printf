/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 23:21:48 by agardner          #+#    #+#             */
/*   Updated: 2018/05/08 01:39:21 by agardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s1, int c)
{
	int i;

	i = 0;
	if (c == '\0')
	{
		while (*s1)
			s1++;
		return ((char *)s1);
	}
	while (s1[i])
		i++;
	i--;
	while (i >= 0)
	{
		if (s1[i] == c)
			return ((char*)&s1[i]);
		i--;
	}
	return (NULL);
}
