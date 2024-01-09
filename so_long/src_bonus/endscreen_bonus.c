/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endscreen_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:30:04 by lbohm             #+#    #+#             */
/*   Updated: 2023/12/14 10:40:26 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	endscreen(t_data *mlx, int wd)
{
	int		i;
	int		pos;

	i = 0;
	mlx->disable = 0;
	while (mlx->map[i])
	{
		pos = 0;
		while (mlx->map[i][pos] && mlx->map[i][pos] != '\n')
		{
			mlx_image_to_window(mlx->mptr, mlx->img[GRASS], pos * 32, i * 32);
			pos++;
		}
		i++;
	}
	endstring(mlx, wd);
}

void	endstring(t_data *mlx, int wd)
{
	char	*text;
	char	*text2;
	char	*text3;
	char	*text4;

	text = "You died!";
	text2 = "You won!";
	text3 = "Press ESC to exit";
	text4 = "Press ESC";
	if (wd == 0)
		mlx_put_string(mlx->mptr, text, (mlx->s.x / 2) - 40,
			(mlx->s.y / 2) - 48);
	else
		mlx_put_string(mlx->mptr, text2, (mlx->s.x / 2) - 40,
			(mlx->s.y / 2) - 48);
	if (mlx->checkban > 0)
		mlx_put_string(mlx->mptr, text3, (mlx->s.x / 2) - 80,
			(mlx->s.y / 2) - 16);
	else
		mlx_put_string(mlx->mptr, text4, (mlx->s.x / 2) - 45,
			(mlx->s.y / 2) - 16);
}
