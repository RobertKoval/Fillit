/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utillity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 19:44:45 by rkoval            #+#    #+#             */
/*   Updated: 2018/01/22 19:56:56 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 *   2x faster strlen than from libft
 */

static size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i + 1] == '\0')
			return (i + 1);
		if (str[i + 2] == '\0')
			return (i + 2);
		if (str[i + 3] == '\0')
			return (i + 3);
		if (str[i + 4] == '\0')
			return (i + 4);
		i += 5;
	}
	return (i);
}

/*
 *   from libft
 */

void			ft_putendl(const char *s)
{
	if (s)
	{
		write(1, s, ft_strlen(s));
		write(1, "\n", 1);
	}
}

void	ft_putstr(const char *s)
{
	if (s)
		write(1, s, ft_strlen(s));
}

static void		ft_bzero(void *s, size_t n)
{
	char *cs;

	cs = s;
	while (n-- > 0)
		*cs++ = '\0';
}
void			*ft_memalloc(size_t size)
{
	char *arr;

	arr = malloc(size);
	if (arr != NULL)
	{
		ft_bzero(arr, size);
		return (arr);
	}
	else
		return (NULL);
}
