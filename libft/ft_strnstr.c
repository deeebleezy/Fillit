/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <bjones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 19:30:38 by bjones            #+#    #+#             */
/*   Updated: 2017/06/26 14:58:47 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t needle_len;

	if (!*little)
		return ((char *)big);
	needle_len = ft_strlen(little);
	while (*big && len > 0)
	{
		if (needle_len > len)
			return (NULL);
		if (*big == *little)
		{
			if (ft_strncmp(big, little, needle_len) == 0)
				return ((char *)big);
		}
		big++;
		len--;
	}
	return (NULL);
}
