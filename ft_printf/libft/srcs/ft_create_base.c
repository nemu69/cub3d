/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacens <jacens@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 17:25:16 by jacens            #+#    #+#             */
/*   Updated: 2021/01/14 15:21:10 by jacens           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_create_base(int size)
{
	char	*ptr;
	int		i;

	if (size > 16 || size < 0 || (ptr = malloc(size + 1)) == NULL)
		return (NULL);
	i = 1;
	while (i != size && i < 10)
	{
		ptr[i] = i;
		i++;
	}
	if (size > 9)
		ptr[i] = 'a';
	if (size > 9)
		ptr[i] = 'b';
	if (size > 9)
		ptr[i] = 'c';
	if (size > 9)
		ptr[i] = 'd';
	if (size > 9)
		ptr[i] = 'e';
	if (size > 9)
		ptr[i] = 'f';
	return (ptr);
}
