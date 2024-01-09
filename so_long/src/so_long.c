/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:44:27 by lbohm             #+#    #+#             */
/*   Updated: 2024/01/09 12:47:33 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data.map = start(argc, argv);
	data.s = sizemap(data.map);
	data.mptr= mlx_init(data.s.x * 32, data.s.y * 32, "so_long", true);
	images(&data);
	wall_and_ground(&data);
	p_c_and_e(&data);
	data.countermoves = 0;
	mlx_set_window_limit(data.mptr, data.mptr->width,
		data.mptr->height, data.mptr->width, data.mptr->height);
	mlx_image_to_window(data.mptr, data.img[DINO], data.x, data.y);
	mlx_key_hook(data.mptr, key, &data);
	mlx_loop(data.mptr);
	mlx_terminate(data.mptr);
	freeall(&data);
	return (0);
}

void	checkinstance(t_data *mlx)
{
	int	i;
	int	z;

	i = 0;
	while (mlx->img[GRASS]->instances[i].z < mlx->img[DINO]->instances[0].z)
		i++;
	z = mlx->img[GRASS]->instances[i].z + 1;
	mlx->img[DINO]->instances[0].z = z;
}

void	key(mlx_key_data_t code, void *param)
{
	t_data		*mlx;

	mlx = param;
	if (code.key == MLX_KEY_ESCAPE && code.action == 1)
		mlx_close_window(mlx->mptr);
	else if ((code.key == MLX_KEY_UP || code.key == MLX_KEY_W)
		&& (code.action == 1 || code.action == 2))
		checkup(mlx);
	else if ((code.key == MLX_KEY_DOWN || code.key == MLX_KEY_S)
		&& (code.action == 1 || code.action == 2))
		checkdown(mlx);
	else if ((code.key == MLX_KEY_LEFT || code.key == MLX_KEY_A)
		&& (code.action == 1 || code.action == 2))
		checkleft(mlx);
	else if ((code.key == MLX_KEY_RIGHT || code.key == MLX_KEY_D)
		&& (code.action == 1 || code.action == 2))
		checkright(mlx);
}
