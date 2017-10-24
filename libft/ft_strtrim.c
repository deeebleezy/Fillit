/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <bjones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 19:20:00 by bjones            #+#    #+#             */
/*   Updated: 2017/06/26 18:25:41 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*ptr;
	size_t	len;

	if (!s)
		return (NULL);
	ptr = (char *)s;
	while (ft_isspace(*ptr))
		ptr++;
	len = ft_strlen(ptr);
	while (len > 0 && ft_isspace(*(ptr + len - 1)))
		len--;
	return (ft_strsub(ptr, 0, len));
}
