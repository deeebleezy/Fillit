/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dtuiasos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 15:48:44 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/06/26 15:49:11 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordct(char *s, char c)
{
	int word_ct;

	while (*s && *s == c)
		s++;
	word_ct = ((*s) ? 1 : 0);
	while (*s)
	{
		if (*s == c && s[1] && s[1] != c)
			word_ct++;
		s++;
	}
	return (word_ct);
}
