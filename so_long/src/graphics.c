/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:25:38 by lbohm             #+#    #+#             */
/*   Updated: 2023/12/14 10:50:20 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	images(t_data *data)
{
	data->text[DINO] = mlx_load_png("./textures/Dinoright.png");
	data->text[GRASS] = mlx_load_png("./textures/GRASSall.png");
	data->text[ROCK] = mlx_load_png("./textures/Rock.png");
	data->text[STEAK] = mlx_load_png("./textures/Steak.png");
	data->text[CAVE] = mlx_load_png("./textures/Cave.png");
	data->img[DINO] = mlx_texture_to_image(data->mptr, data->text[DINO]);
	data->img[GRASS] = mlx_texture_to_image(data->mptr, data->text[GRASS]);
	data->img[ROCK] = mlx_texture_to_image(data->mptr, data->text[ROCK]);
	data->img[STEAK] = mlx_texture_to_image(data->mptr, data->text[STEAK]);
	data->img[CAVE] = mlx_texture_to_image(data->mptr, data->text[CAVE]);
}

void	wall_and_ground(t_data *d)
{
	int	i;
	int	pos;

	i = 0;
	d->s.y = 0;
	while (d->map[i])
	{
		pos = 0;
		d->s.x = 0;
		while (d->map[i][pos] && d->map[i][pos] != '\n')
		{
			if (d->map[i][pos] == '0')
				mlx_image_to_window(d->mptr, d->img[GRASS], d->s.x, d->s.y);
			if (d->map[i][pos] == '1')
				mlx_image_to_window(d->mptr, d->img[ROCK], d->s.x, d->s.y);
			d->s.x += 32;
			pos++;
		}
		d->s.y += 32;
		i++;
	}
}

void	p_c_and_e(t_data *d)
{
	int	i;
	int	pos;

	i = 0;
	d->s.y = 0;
	d->c_all = 0;
	d->countc = 0;
	while (d->map[i])
	{
		pos = 0;
		d->s.x = 0;
		while (d->map[i][pos] && d->map[i][pos] != '\n')
		{
			checkpce(d, i, pos);
			d->s.x += 32;
			pos++;
		}
		d->s.y += 32;
		i++;
	}
}

void	checkpce(t_data *d, int i, int pos)
{
	if (d->map[i][pos] == 'C')
	{
		mlx_image_to_window(d->mptr, d->img[GRASS], d->s.x, d->s.y);
		mlx_image_to_window(d->mptr, d->img[STEAK], d->s.x, d->s.y);
		d->c_all++;
	}
	if (d->map[i][pos] == 'E')
	{
		mlx_image_to_window(d->mptr, d->img[GRASS], d->s.x, d->s.y);
		mlx_image_to_window(d->mptr, d->img[CAVE], d->s.x, d->s.y);
	}
	if (d->map[i][pos] == 'P')
	{
		d->x = d->s.x;
		d->y = d->s.y;
		mlx_image_to_window(d->mptr, d->img[GRASS], d->s.x, d->s.y);
	}
}
