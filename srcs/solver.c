/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dentontui95@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 23:42:59 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/24 14:59:56 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"
#include "../libft/libft.h"

static char	*newsquare(size_t size)
{
	char	*square;
	char	*tmp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	square = (char *)malloc(size * size + size + 1);
	if (!square)
		return (NULL);
	tmp = square;
	while (j++ < size)
	{
		i = 0;
		while (i++ < size)
			*(tmp++) = '.';
		*(tmp++) = '\n';
	}
	*tmp = '\0';
	return (square);
}

static int	addpiece(char *square, t_piece *p)
{
	if (*(square + p->x[1] + p->y[1] * (g_size + 1) - p->x[0]) == '.' &&
	*(square + p->x[2] + p->y[2] * (g_size + 1) - p->x[0]) == '.' &&
	*(square + p->x[3] + p->y[3] * (g_size + 1) - p->x[0]) == '.')
	{
		*square = p->letter;
		*(square + p->x[1] + p->y[1] * (g_size + 1) - p->x[0]) = p->letter;
		*(square + p->x[2] + p->y[2] * (g_size + 1) - p->x[0]) = p->letter;
		*(square + p->x[3] + p->y[3] * (g_size + 1) - p->x[0]) = p->letter;
		p->valid = 0;
		return (1);
	}
	return (0);
}

static void	removepiece(char *square, t_piece *piece)
{
	*square = '.';
	*(square + piece->x[1] + piece->y[1] * (g_size + 1) - piece->x[0]) = '.';
	*(square + piece->x[2] + piece->y[2] * (g_size + 1) - piece->x[0]) = '.';
	*(square + piece->x[3] + piece->y[3] * (g_size + 1) - piece->x[0]) = '.';
	piece->valid = 1;
}

static char	*backtrace(char *square, t_piece *pieces, int piece_nb)
{
	char	*solution;
	int		offset;
	int		piece_i;

	piece_i = -1;
	while (!pieces[++piece_i].valid)
		if (piece_i == 25)
			return (square);
	offset = -1;
	while (++offset < g_size * (g_size + 1) - 4)
	{
		if (*(square + offset) != '.')
			continue;
		if (addpiece(&square[offset], &pieces[piece_nb]))
		{
			solution = backtrace(square, pieces, ++piece_nb);
			if (solution != NULL)
				return (solution);
			removepiece(&square[offset], &pieces[--piece_nb]);
		}
	}
	return (NULL);
}

void		solve(t_piece *pieces)
{
	char	*square;
	char	*solution;

	g_size = 2;
	while (nb_pieces(&pieces[0]) * 4 > g_size * g_size)
		g_size++;
	while (g_size)
	{
		square = newsquare(g_size);
		solution = backtrace(square, &pieces[0], 0);
		if (solution)
		{
			ft_putstr(solution);
			exit(0);
		}
		free(square);
		g_size++;
	}
}
