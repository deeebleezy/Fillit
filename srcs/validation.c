/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dentontui95@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 23:14:46 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/24 14:59:33 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"
#include "../libft/libft.h"

int			valid_format(char *str)
{
	int i;
	int j;

	while (*str)
	{
		j = -1;
		while (++j < 4)
		{
			i = -1;
			while (++i < 4)
			{
				if (*str != '.' && *str != '#')
					return (0);
				str++;
			}
			if (*str != '\n')
				return (0);
			str++;
		}
		if (*str && (*str != '\n' || !*(str + 1)))
			return (0);
		str++;
	}
	return (1);
}

int			valid_hash_count(char *str)
{
	int	hash_ct;
	int	i;

	while (*str)
	{
		hash_ct = 0;
		i = 0;
		while (i < 21 && *str)
		{
			if (*str == '#')
				hash_ct++;
			str++;
			i++;
		}
		if (hash_ct != 4)
			return (0);
	}
	return (1);
}

static int	absval(int i)
{
	if (i < 0)
		return (-1 * i);
	return (i);
}

static int	adj(t_piece *p, int b1, int b2)
{
	if (p->x[b1] == 0 && p->x[b2] == 0 && p->y[b1] == 0 && p->y[b2] == 0)
		return (1);
	if (p->x[b1] == p->x[b2] && absval(p->y[b1] - p->y[b2]) == 1)
		return (1);
	if (p->y[b1] == p->y[b2] && absval(p->x[b1] - p->x[b2]) == 1)
		return (1);
	return (0);
}

int			valid_pieces(t_piece *p)
{
	int i;
	int adj_count;

	i = 0;
	while (i < nb_pieces(&p[0]))
	{
		adj_count = adj(&p[i], 0, 1) + adj(&p[i], 0, 2) + adj(&p[i], 0, 3) +
			adj(&p[i], 1, 0) + adj(&p[i], 1, 2) + adj(&p[i], 1, 3) +
			adj(&p[i], 2, 0) + adj(&p[i], 2, 1) + adj(&p[i], 2, 3) +
			adj(&p[i], 3, 0) + adj(&p[i], 3, 1) + adj(&p[i], 3, 2);
		if (adj_count == 6 || adj_count == 8)
			i++;
		else
			return (0);
	}
	return (1);
}
