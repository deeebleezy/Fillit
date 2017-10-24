/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dentontui95@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 23:36:01 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/24 15:00:14 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"
#include "../libft/libft.h"

void		initialize_pieces(t_piece *pieces)
{
	int i;

	i = 0;
	while (i < 26)
	{
		pieces[i].valid = 0;
		pieces[i].x[0] = 0;
		pieces[i].x[1] = 0;
		pieces[i].x[2] = 0;
		pieces[i].x[3] = 0;
		pieces[i].y[0] = 0;
		pieces[i].y[1] = 0;
		pieces[i].y[2] = 0;
		pieces[i].y[3] = 0;
		pieces[i].letter = 'A' + i;
		i++;
	}
}

void		create_pieces(t_piece *pieces, int piece_nb, char *buf)
{
	int i;
	int j;
	int block_nb;

	while (*(buf) && ++piece_nb != -2)
	{
		j = -1;
		block_nb = 0;
		while (++j < 4)
		{
			i = -1;
			while (++i < 4)
			{
				if (*(buf++) == '#')
				{
					pieces[piece_nb].x[block_nb] = i;
					pieces[piece_nb].y[block_nb] = j;
					block_nb++;
				}
			}
			buf++;
		}
		buf++;
		pieces[piece_nb].valid = 1;
	}
}

static void	shiftleft(t_piece *piece)
{
	piece->x[0]--;
	piece->x[1]--;
	piece->x[2]--;
	piece->x[3]--;
}

static void	shiftup(t_piece *piece)
{
	piece->y[0]--;
	piece->y[1]--;
	piece->y[2]--;
	piece->y[3]--;
}

void		shift_pieces(t_piece *pieces)
{
	int i;

	i = 0;
	while (i < 26)
	{
		while (pieces[i].x[0] != 0 && pieces[i].x[1] != 0 &&
		pieces[i].x[2] != 0 && pieces[i].x[3] != 0)
			shiftleft(&pieces[i]);
		while (pieces[i].y[0] != 0 && pieces[i].y[1] != 0 &&
		pieces[i].y[2] != 0 && pieces[i].y[3] != 0)
			shiftup(&pieces[i]);
		i++;
	}
}
