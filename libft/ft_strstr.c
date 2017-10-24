/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <bjones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 20:36:43 by bjones            #+#    #+#             */
/*   Updated: 2017/06/26 15:47:29 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int len;

	if (!*little)
		return ((char *)big);
	len = ft_strlen(little);
	while (*big)
	{
		if (!(big = ft_strchr(big, (int)*little)))
			return (NULL);
		if (ft_strncmp(big, little, len) == 0)
			return ((char *)big);
		else
			big++;
	}
	return (NULL);
}
