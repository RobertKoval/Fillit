/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 19:22:51 by rkoval            #+#    #+#             */
/*   Updated: 2018/01/22 19:52:48 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
 * Find number of figures in file
 */

size_t			ft_tetcount(const char *str)
{
	size_t count;
	size_t i;

	count = 0;
	i = 0;
	if (str)
	{
		while (str[i] != '\0')
		{
			if (str[i] == '\n')
				count++;
			i++;
		}
		if (i != 0)
			count++;
	}
	return (count / 5);
}

static size_t	ft_fig_width(const char *str, size_t s)
{
	size_t w;
	size_t i;
	size_t j;

	w = 0;
	i = 0;
	while (str[s] != '\n')
	{
		j = s;
		while (i < 4)
		{
			if (str[j] == '#')
			{
				w++;
				break;
			}
			j += 5;
			i++;
		}
		i = 0;
		s++;
	}
	return (w);
}
static size_t	ft_fig_height(const char *str, size_t s)
{
	size_t h;

	h = 0;
	while (!(str[s] == '\n' && (str[s + 1] == '\n'|| str[s + 1] == '\0')))
	{
		if (str[s] == '#')
		{
			h++;
			while (str[s] != '\n')
				s++;
			continue;
		}
		s++;
	}
	return (h);
}

static size_t	ft_isstartoffigure(const char *str, size_t i, size_t e)
{
	while (i < e)
	{
		if (str[i] == '.' && str[i + 1] == '#' && str[i + 5] == '#')
			return (i);
		else if (str[i] == '#')
			return (i);
		else if (str[i + 1] == '#' && str[i + 10] == '#' && str[i + 6] == '#')
			return (i);
		else if (str[i + 5] == '#' && str[i + 2] == '#' && str[i + 1] != '\n')
			return (i);
		i++;
	}
	return (i);
}

/*
 *				Make array with parameter's of figures
 *	0,3,6,9 -> S - start of figure in str
 *	1,4,7,10 -> C - width                       //arr[s][r][c]
 *	2,5,8,11 -> R - height
 */

size_t			*ft_collect_size(const char *str, size_t t_count)
{
	size_t *array;
	size_t i;
	size_t j;
	size_t t;

	if (!(array = (size_t*)malloc(sizeof(size_t) * t_count * 3)))
		return (0);
	i = 0;
	j = 0;
	t = 0;
	while (i < t_count)
	{
		array[t] = ft_isstartoffigure(str, j + i, j + i + 20);
		array[t + 1] = ft_fig_width(str, j + i);
		array[t + 2] = ft_fig_height(str, j + i);
		j += 20;
		t += 3;
		i++;
	}
	return (array);
}
