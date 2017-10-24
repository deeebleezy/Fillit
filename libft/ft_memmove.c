/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dentontui95@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 21:08:33 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/06/22 21:21:50 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*s;
	char		*d;
	size_t		i;

	s = src;
	d = dst;
	i = -1;
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	else
		while (len-- > 0)
			*(d + len) = *(s + len);
	return (dst);
}
