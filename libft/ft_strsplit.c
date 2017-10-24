/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dtuiasos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 21:13:57 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/06/26 15:49:59 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	char	**new;
	char	*start;
	int		word_ct;

	if (!s)
		return (NULL);
	word_ct = ft_wordct((char *)s, c);
	new = (char **)malloc(sizeof(char *) * word_ct + 1);
	if (!new)
		return (NULL);
	start = (char *)s;
	while (*s)
	{
		if (*s == c)
		{
			if (start != s)
				*(new++) = ft_strsub(start, 0, s - start);
			start = (char *)s + 1;
		}
		s++;
	}
	if (start != s)
		*(new++) = ft_strsub(start, 0, s - start);
	*new = NULL;
	return (new - word_ct);
}
