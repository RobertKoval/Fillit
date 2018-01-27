/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 19:09:19 by rkoval            #+#    #+#             */
/*   Updated: 2017/11/20 12:17:53 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_itoa(int n)
{
	long long int	newn;
	char			*str;
	size_t			i;

	newn = n;
	i = 0;
	str = ft_strnew(ft_digilen(newn));
	if (!str)
		return (NULL);
	if (newn < 0)
	{
		str[ft_digilen(newn) - 1] = '-';
		newn *= -1;
	}
	while (newn / 10 > 0)
	{
		str[i++] = (newn % 10 + '0');
		newn /= 10;
	}
	str[i] = (newn % 10 + '0');
	ft_strrev(str);
	return (str);
}
