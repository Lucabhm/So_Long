/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:28:59 by lbohm             #+#    #+#             */
/*   Updated: 2023/12/14 10:40:38 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	checkup(void *param)
{
	t_data	*mlx;

	mlx = param;
	mlx->y = mlx->img[DINO]->instances->y;
	mlx->x = mlx->img[DINO]->instances->x;
	if (mlx->map[(mlx->y / 32) - 1][mlx->x / 32] != '1')
	{
		mlx->countermoves++;
		mlx->img[DINO]->instances->y -= 32;
		mlx->y = mlx->img[DINO]->instances->y;
		ft_printf("Moves: %i\n", mlx->countermoves);
		check_e_and_c(mlx);
		enemy(mlx);
		return (1);
	}
	return (0);
}

int	checkdown(void *param)
{
	t_data	*mlx;

	mlx = param;
	mlx->y = mlx->img[DINO]->instances->y;
	mlx->x = mlx->img[DINO]->instances->x;
	if (mlx->map[(mlx->y / 32) + 1][mlx->x / 32] != '1')
	{
		mlx->countermoves++;
		mlx->img[DINO]->instances->y += 32;
		mlx->y = mlx->img[DINO]->instances->y;
		ft_printf("Moves: %i\n", mlx->countermoves);
		check_e_and_c(mlx);
		enemy(mlx);
		return (1);
	}
	return (0);
}

int	checkleft(void *param)
{
	t_data	*mlx;

	mlx = param;
	mlx->y = mlx->img[DINO]->instances->y;
	mlx->x = mlx->img[DINO]->instances->x;
	if (mlx->map[mlx->y / 32][(mlx->x / 32) - 1] != '1')
	{
		mlx->countermoves++;
		mlx->img[DINO]->instances->x -= 32;
		mlx->x = mlx->img[DINO]->instances->x;
		ft_printf("Moves: %i\n", mlx->countermoves);
		check_e_and_c(mlx);
		enemy(mlx);
		return (1);
	}
	return (0);
}

int	checkright(void *param)
{
	t_data	*mlx;

	mlx = param;
	mlx->y = mlx->img[DINO]->instances->y;
	mlx->x = mlx->img[DINO]->instances->x;
	if (mlx->map[mlx->y / 32][(mlx->x / 32) + 1] != '1')
	{
		mlx->countermoves++;
		mlx->img[DINO]->instances->x += 32;
		mlx->x = mlx->img[DINO]->instances->x;
		ft_printf("Moves: %i\n", mlx->countermoves);
		check_e_and_c(mlx);
		enemy(mlx);
		return (1);
	}
	return (0);
}

void	check_e_and_c(t_data *mlx)
{
	char	*checkcount;
	char	*countermove;

	checkcount = NULL;
	countermove = NULL;
	if (mlx->map[mlx->y / 32][mlx->x / 32] == 'C')
	{
		mlx_image_to_window(mlx->mptr, mlx->img[GRASS],
			mlx->x, mlx->y);
		checkinstance(mlx);
		checkinstancemeteor(mlx);
		mlx->map[(mlx->y / 32)][mlx->x / 32] = '0';
		mlx->countc++;
		mlx->checkcount--;
	}
	string(mlx, checkcount, countermove);
	if ((mlx->map[mlx->y / 32][mlx->x / 32] == 'E'
		|| mlx->map[mlx->y / 32][mlx->x / 32] == 'E')
		&& mlx->countc == mlx->c_all)
	{
		ft_printf("You won the game! with %i steps\n", mlx->countermoves);
		endscreen(mlx, 1);
	}
}
