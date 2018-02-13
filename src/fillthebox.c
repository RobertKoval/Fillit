/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillthebox.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 19:22:51 by rkoval            #+#    #+#             */
/*   Updated: 2018/02/13 13:18:44 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static void	ft_initvar(size_t *a, size_t *b, size_t *c, size_t *d)
{
	if (a != 0)
		*a = 0;
	if (b != 0)
		*b = 0;
	if (c != 0)
		*c = 0;
	if (d != 0)
		*d = 0;
}

static void	ft_rename(char ***box)
{
	size_t i;
	size_t j;
	size_t k;

	ft_initvar(&i, &j, &k, 0);
	while (box[i])
	{
		while (box[i][j])
		{
			while (box[i][j][k])
			{
				if (box[i][j][k] == '#')
					box[i][j][k] = 'A' + i;
				k++;
			}
			k = 0;
			j++;
		}
		j = 0;
		i++;
	}
}

void		ft_fillthebox(const char *s, char ***box, const size_t *coll, \
size_t t_count)
{
	size_t i;
	size_t x;
	size_t y;
	size_t z;
	size_t o;

	ft_initvar(&i, &x, &y, &z);
	o = 0;
	while (x < t_count)
	{
		i = coll[o];
		while (y < coll[o + 2])
		{
			while (z < coll[o + 1])
				box[x][y][z++] = s[i++];
			i = i - coll[o + 1] + 5;
			z = 0;
			y++;
		}
		o += 3;
		y = 0;
		x++;
	}
	ft_rename(box);
}
