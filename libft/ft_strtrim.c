/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 17:27:41 by agardner          #+#    #+#             */
/*   Updated: 2018/05/16 15:38:42 by agardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!s)
		return (ft_strnew(0));
	while (s[j] == '\n' || s[j] == '\t' || s[j] == ' ')
		j++;
	if (s[j] == '\0')
		return (ft_strnew(0));
	while (s[i])
		i++;
	i--;
	while (s[i] == '\n' || s[i] == '\t' || s[i] == ' ')
		i--;
	if (i <= 0)
		return (ft_strnew(0));
	str = ft_strsub(s, j, (i - j) + 1);
	return (str);
}
