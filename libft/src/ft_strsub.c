/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoval <rkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:17:20 by rkoval            #+#    #+#             */
/*   Updated: 2017/11/20 12:10:50 by rkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	str = NULL;
	i = 0;
	if (s)
	{
		str = ft_strnew(len);
		if (str)
		{
			while (i < len)
			{
				str[i++] = s[start++];
			}
			str[i] = '\0';
			return (str);
		}
	}
	return (str);
}
