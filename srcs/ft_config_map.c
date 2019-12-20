/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_config_map.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jacens <jacens@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 16:40:56 by jacens       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/20 01:32:49 by jacens      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube.h"

static int	ft_join_char_more(t_file *file, char *join, int nb)
{
	char	*tmp;

	join[++nb] = '\n';
	join[++nb] = '\0';
	tmp = ft_strjoin(MAP->mapchar, join);
	free(MAP->mapchar);
	free(join);
	MAP->mapchar = tmp;
	return (1);
}

int			ft_join_charmap(t_file *file, char *line, int i, int nb)
{
	char	*join;

	if (!(join = malloc(sizeof(char) * nb + 1)))
	{
		ft_printf("Error\nMalloc\n");
		return (0);
	}
	i = 0;
	nb = -1;
	while (line[i] != '\0')
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
		|| line[i] == 'W')
			if (!(ft_verif_player_config(F, line[i], (nb + 1))))
				return (0);
		line[i] == '\0' ? 0 : (join[++nb] = line[i]);
		line[i] == '\0' ? 0 : i++;
	}
	return (ft_join_char_more(F, join, nb));
}

int			ft_set_line(t_file *file, char *line, int nb, int i)
{
	MAP->height += 1;
	while (line[i] != '\0')
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '2' || line[i] == '1' || line[i] == '0' || line[i] == 'N'
		|| line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
		{
			nb += 1;
			i++;
		}
		else if (line[i] != '\0')
		{
			free(MAP->mapchar);
			ft_printf("Error\nMap 2\n");
			return (0);
		}
	}
	if (nb == 0)
		return (1);
	else if (nb == MAP->width)
		return (2);
	free(MAP->mapchar);
	ft_printf("Error\nMap 3\n");
	return (0);
}

int			ft_first_line_map(char *line, int i, int nb, t_file *file)
{
	MAP->height += 1;
	while (line[++i] != '\0')
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '1')
		{
			nb += 1;
			i++;
		}
		else if (line[i] != '\0')
		{
			free(line);
			ft_printf("Error\nMap1\n");
			return (0);
		}
	}
	free(line);
	return (nb);
}

int			ft_config_map(int fd, char *line, t_file *file)
{
	int i;

	if (!((MAP->width = ft_first_line_map(line, -1, 0, file)) &&
		(MAP->mapchar = ft_calloc(MAP->width + 2, 1))))
	{
		ft_printf("Error\nMalloc\n");
		return (0);
	}
	ft_memset(MAP->mapchar, 49, MAP->width + 1);
	MAP->mapchar[MAP->width] = '\n';
	while (get_next_line(fd, &line) >= 0)
	{
		if (!(i = ft_set_line(F, line, 0, 0)))
			return (0);
		else if (i == 1)
			return (1);
		else
		{
			if (!(ft_join_charmap(F, line, 0, i)))
				return (0);
		}
		free(line);
	}
	return (1);
}
