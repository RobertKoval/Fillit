/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 19:22:50 by rkoval            #+#    #+#             */
/*   Updated: 2018/02/13 13:14:36 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static void		ft_add(char **map, size_t r, size_t c, char **box)
{
	size_t i;
	size_t j;

	i = 0;
	while (box[i])
	{
		j = 0;
		while (box[i][j])
		{
			if (box[i][j] != '.')
				map[r + i][c + j] = box[i][j];
			j++;
		}
		i++;
	}
}

static size_t	ft_canpaste(char **map, size_t r, size_t c, char **box)
{
	size_t i;
	size_t j;

	i = 0;
	while (box[i])
	{
		j = 0;
		while (box[i][j])
		{
			if ((map[r + i] == NULL || box[i][j] != '.') && \
					map[r + i][c + j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void		ft_remove(char **map, size_t r, size_t c, char **box)
{
	size_t i;
	size_t j;

	i = 0;
	while (box[i])
	{
		j = 0;
		while (box[i][j])
		{
			if (box[i][j] == '.')
				j++;
			else
				map[r + i][c + j++] = '.';
		}
		i++;
	}
}

/*
**  Backtracking algorithm for filling map
*/

static size_t	ft_solver(char **map, char ***box, size_t m_size, size_t *coll)
{
	size_t r;
	size_t c;

	r = 0;
	c = 0;
	if (!*box)
		return (1);
	while (r + coll[2] - 1 < m_size)
	{
		while (c + coll[1] - 1 < m_size)
		{
			if (ft_canpaste(map, r, c, *box))
			{
				ft_add(map, r, c, *box);
				if (ft_solver(map, box + 1, m_size, coll + 3))
					return (1);
				ft_remove(map, r, c, *box);
			}
			c++;
		}
		c = 0;
		r++;
	}
	return (0);
}

void			ft_fillit(const char *str, size_t t_count)
{
	char	**map;
	char	***box;
	size_t	*collect;
	size_t	m_size;
	size_t	i;

	i = 0;
	collect = ft_collect_size(str, t_count);
	box = ft_makebox(t_count, collect);
	ft_fillthebox(str, box, collect, t_count);
	m_size = ft_mapsize(t_count * 4);
	map = ft_initmap(m_size);
	while (ft_solver(map, box, m_size, collect) != 1)
	{
		ft_cleanmap(map);
		m_size++;
		map = ft_initmap(m_size);
	}
	while (i < m_size)
		ft_putstr(map[i++]);
	ft_cleanmap(map);
	ft_cleanbox(box, collect);
	free(collect);
}
