/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makebox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 19:22:51 by rkoval            #+#    #+#             */
/*   Updated: 2018/02/13 13:15:26 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static void	ft_setcount(size_t *a, size_t *b, size_t *c)
{
	*a = *a + 3;
	*b = 0;
	*c = *c + 1;
}

/*
** Make 3-D box with figures (width x height)
*/

char		***ft_makebox(size_t t_count, const size_t *coll)
{
	char	***array;
	size_t	i;
	size_t	j;
	size_t	o;

	i = 0;
	j = 0;
	o = 0;
	if (!(array = (char***)malloc(sizeof(char**) * t_count + 8)))
		return (NULL);
	while (i < t_count)
	{
		if (!(array[i] = (char**)malloc(sizeof(char*) * coll[o + 2] + 8)))
			return (NULL);
		while (j < coll[o + 2])
		{
			if (!(array[i][j] = ft_memalloc(sizeof(char) * coll[o + 1] + 1)))
				return (NULL);
			j++;
		}
		array[i][j] = NULL;
		ft_setcount(&o, &j, &i);
	}
	array[i] = NULL;
	return (array);
}

/*
** Free 3-D box after using
*/

void		ft_cleanbox(char ***box, const size_t *coll)
{
	size_t o;
	size_t z;
	size_t f;

	f = 0;
	o = 2;
	while (box[f])
	{
		z = 0;
		while (z < coll[o])
			free(box[f][z++]);
		free(box[f]);
		o += 3;
		f++;
	}
	free(box);
}
