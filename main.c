/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:31:39 by rkoval            #+#    #+#             */
/*   Updated: 2018/01/22 19:46:56 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_error(const char *str)
{
	ft_putendl(str);
	exit(1);
}

int			main(int argc, char **argv)
{
	int		fd;
	char	buf[BUF_SIZE + 1];
	int		red;

	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
		ft_error("usage: fillit input_file");
	if (fd == -1)
		ft_error("error");
	red = read(fd, buf, BUF_SIZE);
	if (red == -1)
		ft_error("error");
	buf[red] = '\0';
	close(fd);
	if (!ft_validfile(buf))
		ft_error("error");
	else
		ft_fillit(buf, ft_tetcount(buf));
	return (0);
}
