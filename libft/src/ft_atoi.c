/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:33:46 by rkoval            #+#    #+#             */
/*   Updated: 2017/11/19 19:49:47 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_atoi(const char *str)
{
	size_t	result;
	size_t	minus;
	size_t	i;

	result = 0;
	minus = 1;
	i = 0;
	while (ft_isspace(str[i]) || (str[i] == '+' && ft_isdigit(str[i + 1])))
		i++;
	if (str[i] == '-')
	{
		minus = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result += str[i++] - '0';
		if (ft_isdigit(str[i]))
			result *= 10;
	}
	return (result * minus);
}
