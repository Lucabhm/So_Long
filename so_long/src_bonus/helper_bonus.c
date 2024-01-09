/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:00:25 by lbohm             #+#    #+#             */
/*   Updated: 2023/12/14 10:40:35 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

char	**dupmap(char **map, t_pos size)
{
	char	**cpymap;
	int		i;
	int		pos;

	i = 0;
	cpymap = (char **)malloc ((size.y + 1) * sizeof(char *));
	if (!(cpymap))
		error(9);
	while (map[i])
	{
		cpymap[i] = (char *)malloc ((size.x + 1) * sizeof (char));
		if (!(cpymap[i]))
			error(freearr(cpymap));
		pos = 0;
		while (map[i][pos] && map[i][pos] != '\n')
		{
			cpymap[i][pos] = map[i][pos];
			pos++;
		}
		cpymap[i][pos] = '\0';
		i++;
	}
	cpymap[i] = NULL;
	return (cpymap);
}

int	freearr(char **cpyarr)
{
	int	i;

	i = 0;
	while (cpyarr[i])
	{
		free(cpyarr[i]);
		i++;
	}
	free(cpyarr);
	return (10);
}

int	rowlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

t_pos	sizemap(char **map)
{
	t_pos	size;

	size.y = 0;
	size.x = 0;
	while (map[size.y])
	{
		size.x = 0;
		while (map[size.y][size.x] && map [size.y][size.x] != '\n')
		{
			size.x++;
		}
		size.y++;
	}
	return (size);
}

void	freeall(t_data *mlx)
{
	int	i;

	i = 0;
	while (mlx->map[i])
	{
		free(mlx->map[i]);
		i++;
	}
	free(mlx->map);
	i = 0;
	while (i < SIZE)
	{
		mlx_delete_texture(mlx->text[i]);
		i++;
	}
	i = 0;
	while (i < mlx->xcount)
	{
		free(mlx->yenemy[i]);
		free(mlx->xenemy[i]);
		i++;
	}
	free(mlx->yenemy);
	free(mlx->xenemy);
}
