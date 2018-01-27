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

#include "../includes/fillit.h"

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

	if (argc != 2)
		ft_error("usage: fillit input_file");
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_error("error");
	if ((red = read(fd, buf, BUF_SIZE)) == -1)
	{
		close(fd);
		ft_error("error");
	}
	if (close(fd) == -1)
		ft_error("error");
	buf[red] = '\0';
	if (!ft_validfile(buf))
		ft_error("error");
	else
		ft_fillit(buf, ft_tetcount(buf));
	return (0);
}
