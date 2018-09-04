/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 21:31:38 by agardner          #+#    #+#             */
/*   Updated: 2018/05/22 00:49:43 by agardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(const char *s, char c)
{
	char			**arr;
	t_varcounters	strukt;

	strukt.i = 0;
	strukt.word = 0;
	if (!s || !c)
		return (NULL);
	strukt.count = ft_wordcount(s, c);
	if (!(arr = (char**)malloc(sizeof(char*) * strukt.count + 1)))
		return (NULL);
	while (s[strukt.i] && strukt.word < strukt.count)
	{
		while (s[strukt.i] == c)
			strukt.i++;
		if (s[strukt.i] == '\0')
			break ;
		strukt.len = ft_count2delimit(&s[strukt.i], c);
		arr[strukt.word] = ft_strsub(s, strukt.i, strukt.len);
		strukt.i += strukt.len;
		strukt.word++;
	}
	arr[strukt.word] = NULL;
	return (arr);
}
