/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init2.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/19 20:04:18 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/20 07:13:11 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube.h"

int		ft_init_draw(t_file *file)
{
	if (!(DRAW = malloc(sizeof(t_draw))))
	{
		ft_free_fil(F);
		ft_printf("Error\nMalloc ray\n");
		return (0);
	}
	DRAW->start = 0;
	DRAW->end = 0;
	DRAW->lineheight = 0;
	return (1);
}

int		ft_init_key(t_file *file)
{
	if (!(KEY = malloc(sizeof(t_key))))
	{
		ft_free_fil(F);
		ft_printf("Error\nMalloc key\n");
		return (0);
	}
	KEY->mvleft = 0;
	KEY->mvright = 0;
	KEY->left = 0;
	KEY->right = 0;
	KEY->up = 0;
	KEY->down = 0;
	return (1);
}
