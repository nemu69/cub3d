/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacens <jacens@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:29:57 by jacens            #+#    #+#             */
/*   Updated: 2021/01/14 15:21:10 by jacens           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*vs1;
	const char	*vs2;

	i = 0;
	vs1 = (const char *)s1;
	vs2 = (const char *)s2;
	while (i != n)
	{
		if ((unsigned char)vs1[i] != (unsigned char)vs2[i])
			return ((unsigned char)vs1[i] - (unsigned char)vs2[i]);
		i++;
	}
	return (0);
}
