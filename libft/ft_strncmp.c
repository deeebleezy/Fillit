/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dentontui95@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 21:51:34 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/07/17 18:11:55 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 && *s2 && n-- > 1)
		if (*(s1++) != *(s2++))
			return ((unsigned char)*(--s1) - (unsigned char)*(--s2));
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
