/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_va.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacens <jacens@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:12:40 by jacens            #+#    #+#             */
/*   Updated: 2021/01/14 15:21:11 by jacens           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_va_null_char(va_list *args, t_print *struc)
{
	char *ptr;

	ptr = va_arg(*args, char *);
	if (!ptr)
	{
		if (!(ptr = ft_strdup("(null)")))
			return (NULL);
		return (ptr);
	}
	if (struc->dot == 1 && struc->space == 0 && struc->zero == -1)
	{
		if (!(ptr = ft_strdup("(null)")))
			return (NULL);
		return (ptr);
	}
	if (!(ptr = ft_strdup(ptr)))
		return (NULL);
	return (ptr);
}

int		ft_va_null_int(va_list *args, t_print *struc)
{
	int i;

	i = va_arg(*args, int);
	if (i == 0)
		struc->intnull = 1;
	return (i);
}
