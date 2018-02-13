/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 19:22:51 by rkoval            #+#    #+#             */
/*   Updated: 2018/02/13 13:19:16 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** Find minimum size of map (number of figures (f) * 4)
*/

size_t	ft_mapsize(size_t f)
{
	size_t s;

	s = 2;
	while (s * s < f)
		s++;
	return (s);
}

/*
** Build 2-D array (MAP for figures)
*/

char	**ft_initmap(size_t size)
{
	char	**array;
	size_t	i;
	int		j;

	i = 0;
	if (!(array = (char**)malloc(sizeof(char*) * size + 8)))
		return (NULL);
	while (i < size)
	{
		j = -1;
		if (!(array[i] = (char*)malloc(sizeof(char) * size + 2)))
		{
			free(array);
			return (NULL);
		}
		while (j++ < (int)size)
			array[i][j] = '.';
		array[i][size] = '\n';
		array[i][size + 1] = '\0';
		i++;
	}
	array[i] = NULL;
	return (array);
}

void	ft_cleanmap(char **map)
{
	size_t k;

	k = 0;
	while (map[k])
		free(map[k++]);
	free(map);
}
