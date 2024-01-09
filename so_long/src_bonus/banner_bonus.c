/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   banner_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:44:39 by lbohm             #+#    #+#             */
/*   Updated: 2023/12/14 13:31:40 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	printbanner(t_data *mlx)
{
	int		pos;
	char	*text;

	pos = 0;
	mlx->checkban = 0;
	text = "Moves: ";
	if (mlx->s.x / 32 > 5)
	{
		mlx->checkban = 1;
		biggerfive(mlx, pos);
		mlx_put_string(mlx->mptr, text, 2 * 19, mlx->s.y + 5);
	}
	else
		lowerfive(mlx, pos);
	if (mlx->s.x / 32 >= 10)
		biggerten(mlx, pos);
}

void	lowerfive(t_data *mlx, int pos)
{
	mlx->checkban = 0;
	while (mlx->map[0][pos])
	{
		if (pos == 0)
			mlx_image_to_window(mlx->mptr, mlx->img[BANL],
				pos * 32, mlx->s.y);
		else if (mlx->map[0][pos + 1] == '\n')
			mlx_image_to_window(mlx->mptr, mlx->img[BANR],
				pos * 32, mlx->s.y);
		else
			mlx_image_to_window(mlx->mptr, mlx->img[BANM],
				pos * 32, mlx->s.y);
		pos++;
	}
}

void	biggerfive(t_data *mlx, int pos)
{
	while (mlx->map[0][pos] != '\n')
	{
		if (pos == 0)
			mlx_image_to_window(mlx->mptr, mlx->img[BANL],
				pos * 32, mlx->s.y);
		else if (pos == 1)
			mlx_image_to_window(mlx->mptr, mlx->img[BANWL],
				pos * 32, mlx->s.y);
		else if (pos == 2)
			mlx_image_to_window(mlx->mptr, mlx->img[BANWM],
				pos * 32, mlx->s.y);
		else if (pos == 3)
			mlx_image_to_window(mlx->mptr, mlx->img[BANWM],
				pos * 32, mlx->s.y);
		else if (pos == 4)
			mlx_image_to_window(mlx->mptr, mlx->img[BANWR],
				pos * 32, mlx->s.y);
		else if (mlx->map[0][pos + 1] == '\n')
			mlx_image_to_window(mlx->mptr, mlx->img[BANR],
				pos * 32, mlx->s.y);
		else
			mlx_image_to_window(mlx->mptr, mlx->img[BANM],
				pos * 32, mlx->s.y);
		pos++;
	}
}

void	biggerten(t_data *mlx, int pos)
{
	char	*text2;
	int		x;

	mlx->checkban = 2;
	pos = 0;
	text2 = "Steaks: ";
	x = mlx->s.x / 32;
	while (pos < x)
	{
		if (pos + 5 == x)
			mlx_image_to_window(mlx->mptr, mlx->img[BANWL], pos * 32, mlx->s.y);
		else if (pos + 4 == x)
			mlx_image_to_window(mlx->mptr, mlx->img[BANWM], pos * 32, mlx->s.y);
		else if (pos + 3 == x)
			mlx_image_to_window(mlx->mptr, mlx->img[BANWM], pos * 32, mlx->s.y);
		else if (pos + 2 == x)
			mlx_image_to_window(mlx->mptr, mlx->img[BANWR], pos * 32, mlx->s.y);
		pos++;
	}
	mlx_put_string(mlx->mptr, text2, mlx->s.x - 155, mlx->s.y + 5);
}

void	string(t_data *mlx, char *checkcount, char *countermove)
{
	if (mlx->checkban == 1 || mlx->checkban == 2)
	{
		if (mlx->checkban == 2)
		{
			checkcount = ft_itoa(mlx->checkcount);
			mlx_image_to_window(mlx->mptr, mlx->img[BANWM],
				mlx->s.x - 85, mlx->s.y);
			mlx_image_to_window(mlx->mptr, mlx->img[BANWR],
				mlx->s.x - 64, mlx->s.y);
			mlx_put_string(mlx->mptr, checkcount, mlx->s.x - 80, mlx->s.y + 5);
			free(checkcount);
		}
		countermove = ft_itoa(mlx->countermoves);
		mlx_image_to_window(mlx->mptr, mlx->img[BANWM], 3 * 32, mlx->s.y);
		mlx_image_to_window(mlx->mptr, mlx->img[BANWR], 4 * 32, mlx->s.y);
		mlx_put_string(mlx->mptr, countermove, 5 * 21, mlx->s.y + 5);
		free(countermove);
	}
}
