/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dentontui95@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 21:08:43 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/06/22 21:17:02 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	render(int n, int fd)
{
	if (n >= 10 || n <= -10)
	{
		render(n / 10, fd);
		render(n % 10, fd);
	}
	else
	{
		if (n >= 0)
			ft_putchar_fd(n + '0', fd);
		else
			ft_putchar_fd(-1 * n + '0', fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	render(n, fd);
}
