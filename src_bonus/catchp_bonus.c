/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catchp_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:31:16 by lbohm             #+#    #+#             */
/*   Updated: 2023/12/14 10:40:20 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	catchpy(t_pos *p, t_pos *e, int y)
{
	int	player;
	int	enemeyaftery;

	player = p->y - e->y;
	enemeyaftery = p->y - y;
	if (player < 0)
		player *= -1;
	if (enemeyaftery < 0)
		enemeyaftery *= -1;
	if (player >= enemeyaftery)
		return (1);
	return (0);
}

int	catchpx(t_pos *p, t_pos *e, int x)
{
	int	enemey;
	int	enemeyafterx;

	enemey = p->x - e->x;
	enemeyafterx = p->x - x;
	if (enemey < 0)
		enemey *= -1;
	if (enemeyafterx < 0)
		enemeyafterx *= -1;
	if (enemey >= enemeyafterx)
		return (2);
	return (0);
}

void	checkx(t_data *mlx, t_pos *e)
{
	if (mlx->map[e->y][e->x] == 'X')
		mlx->map[e->y][e->x] = '0';
}
