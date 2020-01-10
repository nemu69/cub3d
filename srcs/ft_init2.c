/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init2.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/19 20:04:18 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 10:43:47 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube.h"

int			ft_init_draw(t_file *file)
{
	if (!(F->D = malloc(sizeof(t_draw))))
	{
		ft_free_fil(F);
		ft_printf("Error\nMalloc ray\n");
		return (0);
	}
	F->D->start = 0;
	F->D->end = 0;
	F->D->lineheight = 0;
	return (1);
}

int			ft_init_key(t_file *file)
{
	if (!(F->K = malloc(sizeof(t_key))))
	{
		ft_free_fil(F);
		ft_printf("Error\nMalloc key\n");
		return (0);
	}
	F->K->mvleft = 0;
	F->K->mvright = 0;
	F->K->left = 0;
	F->K->right = 0;
	F->K->up = 0;
	F->K->down = 0;
	return (1);
}

t_sprite	*ft_init_sprite(t_file *file, int x, int y, float dist)
{
	t_sprite *sprite;

	if (!(SP = malloc(sizeof(t_sprite))))
	{
		ft_free_fil(F);
		ft_printf("Error\nMalloc sprite\n");
		return (NULL);
	}
	SP->y = y + 0.5;
	SP->x = x + 0.5;
	SP->dist = dist;
	SP->next = NULL;
	return (SP);
}

int			ft_init_draw_sprite(t_file *file)
{
	if (!(F->DP = malloc(sizeof(t_draspr))))
	{
		ft_free_fil(F);
		ft_printf("Error\nMalloc draw sprite\n");
		return (0);
	}
	return (1);
}

int			ft_init_imgw(t_file *file)
{
	if (!(F->IW = malloc(sizeof(t_imgw))))
	{
		ft_free_fil(F);
		ft_printf("Error\nMalloc image wall\n");
		return (0);
	}
	F->IW->text[0] = NULL;
	F->IW->text[1] = NULL;
	F->IW->text[2] = NULL;
	F->IW->text[3] = NULL;
	F->IW->text[4] = NULL;
	F->IW->text[5] = NULL;
	F->IW->img[0] = NULL;
	F->IW->img[1] = NULL;
	F->IW->img[2] = NULL;
	F->IW->img[3] = NULL;
	F->IW->img[4] = NULL;
	F->IW->img[5] = NULL;
	return (1);
}
