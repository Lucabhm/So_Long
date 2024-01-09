/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:14:18 by lbohm             #+#    #+#             */
/*   Updated: 2023/12/14 10:40:29 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	enemy(void *param)
{
	t_data	*mlx;
	t_pos	enemy;
	t_pos	player;
	int		i;

	mlx = param;
	player.y = mlx->img[DINO]->instances->y / 32;
	player.x = mlx->img[DINO]->instances->x / 32;
	i = 0;
	mlx->rlud = 0;
	while (mlx->xcount > i)
	{
		enemy.y = mlx->yenemy[i][0];
		enemy.x = mlx->xenemy[i][0];
		if (enemyleftup(mlx, &player, &enemy, i))
			enemyrightdown(mlx, &player, &enemy, i);
		mlx->rlud = 0;
		i++;
	}
	if (mlx->map[player.y][player.x] == 'X')
	{
		endscreen(mlx, 0);
		ft_printf("You died!\n");
	}
}

void	mallocx(t_data *mlx)
{
	int	i;

	i = 0;
	mlx->yenemy = (int **)malloc ((mlx->xcount + 1) * sizeof(int *));
	if (!(mlx->yenemy))
		error(9);
	mlx->xenemy = (int **)malloc ((mlx->xcount + 1) * sizeof(int *));
	if (!(mlx->xenemy))
		error(9);
	while (mlx->xcount > i)
	{
		mlx->yenemy[i] = (int *)malloc (sizeof(int));
		if (!(mlx->yenemy[i]))
			error(10);
		mlx->xenemy[i] = (int *)malloc (sizeof(int));
		if (!(mlx->xenemy))
			error(10);
		i++;
	}
	mlx->yenemy[i] = NULL;
	mlx->xenemy[i] = NULL;
	mlx->xcount = 0;
}

void	checkinstancemeteor(t_data *mlx)
{
	int	i;
	int	z;
	int	j;

	j = 0;
	while (mlx->xcount > j)
	{
		i = 0;
		while (mlx->img[GRASS]->instances[i].z
			< mlx->img[DINO]->instances[0].z - 1)
			i++;
		z = mlx->img[GRASS]->instances[i].z;
		mlx->img[METEOR]->instances[j].z = z + 2;
		j++;
	}
}

int	enemyleftup(t_data *mlx, t_pos *p, t_pos *e, int i)
{
	if (mlx->map[e->y][e->x - 1] != '1' && mlx->map[e->y][e->x - 1] != 'X'
		&& catchpx(p, e, e->x - 1) == 2 && mlx->rlud < 1)
	{
		mlx->img[METEOR]->instances[i].x -= 32;
		checkx(mlx, e);
		if (mlx->map[e->y][e->x - 1] == '0')
			mlx->map[e->y][e->x - 1] = 'X';
		mlx->xenemy[i][0] -= 1;
		mlx->rlud++;
		if (mlx->map[p->y][p->x] == 'X')
			return (0);
	}
	if (mlx->map[e->y - 1][e->x] != '1' && mlx->map[e->y - 1][e->x] != 'X'
		&& catchpy(p, e, e->y - 1) == 1 && mlx->rlud < 1)
	{
		mlx->img[METEOR]->instances[i].y -= 32;
		checkx(mlx, e);
		if (mlx->map[e->y - 1][e->x] == '0')
			mlx->map[e->y - 1][e->x] = 'X';
		mlx->yenemy[i][0] -= 1;
		mlx->rlud++;
		if (mlx->map[p->y][p->x] == 'X')
			return (0);
	}
	return (1);
}

int	enemyrightdown(t_data *mlx, t_pos *p, t_pos *e, int i)
{
	if (mlx->map[e->y][e->x + 1] != '1' && mlx->map[e->y][e->x + 1] != 'X'
		&& catchpx(p, e, e->x + 1) == 2 && mlx->rlud < 1)
	{
		mlx->img[METEOR]->instances[i].x += 32;
		checkx(mlx, e);
		if (mlx->map[e->y][e->x + 1] == '0')
			mlx->map[e->y][e->x + 1] = 'X';
		mlx->xenemy[i][0] += 1;
		mlx->rlud++;
		if (mlx->map[p->y][p->x] == 'X')
			return (0);
	}
	if (mlx->map[e->y + 1][e->x] != '1' && mlx->map[e->y + 1][e->x] != 'X'
		&& catchpy(p, e, e->y + 1) == 1 && mlx->rlud < 1)
	{
		mlx->img[METEOR]->instances[i].y += 32;
		checkx(mlx, e);
		if (mlx->map[e->y + 1][e->x] == '0')
			mlx->map[e->y + 1][e->x] = 'X';
		mlx->yenemy[i][0] += 1;
		if (mlx->map[p->y][p->x] == 'X')
			return (0);
	}
	return (1);
}
