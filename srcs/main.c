/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dentontui95@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 22:13:45 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/24 15:00:29 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"
#include "../libft/libft.h"

#define BUF_SIZE 547

int			nb_pieces(t_piece *pieces)
{
	int nb_pieces;

	nb_pieces = 0;
	while (pieces[nb_pieces].valid && nb_pieces < 26)
		nb_pieces++;
	return (nb_pieces);
}

static void	terminate(void)
{
	ft_putendl("error");
	exit(1);
}

static char	*new_buffer(char *str)
{
	int		fd;
	int		ret;
	char	*buf;

	buf = (char *)malloc(BUF_SIZE);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		terminate();
	ret = read(fd, buf, BUF_SIZE);
	close(fd);
	if (ret == -1 || ret == 0)
		terminate();
	buf[ret] = '\0';
	buf[ret + 1] = '\0';
	return (buf);
}

int			main(int argc, char **argv)
{
	char	*buf;
	t_piece pieces[26];

	if (argc != 2)
	{
		ft_putstr("usage: ");
		ft_putstr(argv[0] + 2);
		ft_putstr(" source_file\n");
		exit(1);
	}
	buf = new_buffer(argv[1]);
	if (!valid_format(buf) || !valid_hash_count(buf))
		terminate();
	initialize_pieces(&pieces[0]);
	create_pieces(&pieces[0], -1, buf);
	if (!valid_pieces(&pieces[0]))
		terminate();
	shift_pieces(&pieces[0]);
	solve(&pieces[0]);
	return (0);
}
