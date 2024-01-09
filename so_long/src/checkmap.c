/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:14:51 by lbohm             #+#    #+#             */
/*   Updated: 2023/12/14 10:52:09 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	checkmap(char **map)
{
	t_player	count;
	t_pos		size;
	int			p;
	int			c;
	int			e;

	p = 0;
	c = 0;
	e = 0;
	count.p = &p;
	count.c = &c;
	count.e = &e;
	checker_n_and_r(map);
	size = sizemap(map);
	checker(map, count, size);
	if ((*count.p) != 1 || (*count.c) == 0 || (*count.e) != 1)
	{
		freearr(map);
		errorcounter(count);
	}
	checkpath(map, size, count);
}

void	checker_n_and_r(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] == '\n')
			errormap(3, map);
		i++;
	}
	i = 0;
	while (map[i + 1])
	{
		if (rowlen(map[i]) != rowlen(map[i + 1]))
			errormap(4, map);
		i++;
	}
}

void	checker(char **map, t_player count, t_pos size)
{
	int	i;
	int	pos;

	i = 0;
	while (map[i])
	{
		pos = 0;
		while (map[i][pos] && map[i][pos] != '\n')
		{
			if (map[0][pos] != '1' || map[size.y - 1][pos] != '1'
				|| map[i][0] != '1' || map[i][size.x - 1] != '1')
				errormap(5, map);
			checkerinside(map, map[i][pos], count);
			pos++;
		}
		i++;
	}
}

void	checkerinside(char **map, char letter, t_player count)
{
	if (letter == 'P')
		(*count.p)++;
	else if (letter == 'C')
		(*count.c)++;
	else if (letter == 'E')
		(*count.e)++;
	else if (letter != '1' && letter != '0')
		errormap(6, map);
}
