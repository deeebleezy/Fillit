/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjones <BJones033@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 22:18:46 by bjones            #+#    #+#             */
/*   Updated: 2017/07/17 17:46:56 by bjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*char_ptr;

	char_ptr = (unsigned char *)b;
	while (len-- > 0)
		*((unsigned char *)char_ptr++) = (unsigned char)c;
	return (b);
}
