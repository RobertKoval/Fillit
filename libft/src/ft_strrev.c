/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 10:38:06 by rkoval            #+#    #+#             */
/*   Updated: 2017/11/19 16:21:12 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_strrev(char *a)
{
	char	p;
	size_t	start;
	size_t	end;

	start = 0;
	if (a && ft_strlen(a) != 0)
	{
		end = ft_strlen(a) - 1;
		while (start < end)
		{
			p = a[start];
			a[start] = a[end];
			a[end] = p;
			start++;
			end--;
		}
	}
}
