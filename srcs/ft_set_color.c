/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_set_color.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 18:07:58 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 13:33:01 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube.h"

int			*ft_readxpm(t_file *file, char *str, int n)
{
	int		*data;
	int		bits;
	int		sl;
	int		endian;

	data = NULL;
	if ((F->IW->img[n] = mlx_xpm_file_to_image(F->mlx, str, &F->IW->width[n],
		&F->IW->height[n])))
		data = (int *)mlx_get_data_addr(F->IW->img[n], &bits, &sl, &endian);
	return (data);
}

int			ft_rgbtoint(int red, int green, int blue)
{
	return ((256 * 256 * red) + (256 * green) + blue);
}
