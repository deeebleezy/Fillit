/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dentontui95@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 23:18:32 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/24 15:06:37 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>

int				g_size;
typedef struct	s_piece
{
	int		x[4];
	int		y[4];
	int		valid;
	char	letter;
}				t_piece;

/*
** MAIN
*/
int				nb_pieces(t_piece *pieces);

/*
** VALIDATION
*/
int				valid_format(char *str);
int				valid_hash_count(char *str);
int				valid_pieces(t_piece *p);

/*
** PIECE_CREATION
*/
void			initialize_pieces(t_piece *pieces);
void			create_pieces(t_piece *pieces, int piece_nb, char *buf);
void			shift_pieces(t_piece *pieces);

/*
** SOLVER
*/
void			solve(t_piece *pieces);

#endif
