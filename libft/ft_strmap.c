/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dtuiasos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 00:30:46 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/06/26 14:58:18 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	int		i;

	if (!s)
		return (NULL);
	new = (char *)malloc(ft_strlen(s) + 1);
	if (!new)
		return (NULL);
	i = -1;
	while (*(s + ++i))
		*(new + i) = f(*(s + i));
	*(new + i) = '\0';
	return (new);
}
