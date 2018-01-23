/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 19:22:51 by rkoval            #+#    #+#             */
/*   Updated: 2018/01/22 20:10:54 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 * Validation tetraminos for first and last '#'
 */
static size_t	ft_validn(const char *str)
{
	size_t n;
	size_t i;

	n = 0;
	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] == '\n')
			n++;
		if (n == 4)
		{
			if (str[i + 1] != '\n' && str[i + 1] != '\0')
				return (0);
			n = 0;
			i++;
		}
		i++;
	}
	if (n != 0)
		return (0);
	return (1);
}

static size_t	ft_validtet(const char *str)
{
	size_t i;
	size_t con;
	size_t pos;

	con = 0;
	i = 0;
	pos = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (i + 1 < pos + 19 && str[i + 1] == '#')
				con++;
			if (i + 5 < pos + 19 && str[i + 5] == '#')
				con++;
			if (i - 1 >= pos && str[i - 1] == '#')
				con++;
			if (i - 5 >= pos && str[i - 5] == '#')
				con++;
		}
		if (str[i] == '\n' && (str[i + 1] == '\n' || str[i + 1] == '\0'))
		{
			pos += 21;
			if (con != 6 && con != 8)
				return (0);
			con = 0;
		}
		i++;
	}
	return (1);
}

/*
 * Validation file for '.' and '#' count and
 * checking if there are some other symbols
 */

size_t			ft_validfile(const char *str)
{
	size_t i;
	size_t t;
	size_t p;

	t = 0;
	p = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '#' && str[i] != '.' && str[i] != '\n')
			return (0);
		if (str[i] == '#')
			t++;
		if (str[i] == '.')
			p++;
		i++;
	}
	if (t % 4 != 0 || p % 12 != 0 || i < 20 || p / t != 3)
		return (0);
	if (!ft_validn(str))
		return (0);
	return (ft_validtet(str));
}
