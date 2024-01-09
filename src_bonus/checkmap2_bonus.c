/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:17:29 by lucabhm           #+#    #+#             */
/*   Updated: 2023/12/14 10:40:22 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	checkpath(char **map, t_pos size, t_player count)
{
	t_pos	start;
	char	**cpymap;

	(*count.p) = 0;
	(*count.c) = 0;
	(*count.e) = 0;
	start = search_p(map);
	cpymap = dupmap(map, size);
	fillmap(cpymap, size, start);
	counter(cpymap, count);
	freearr(cpymap);
	if ((*count.p) != 0 || (*count.c) != 0 || (*count.e) != 0)
		errormap(7, map);
}

t_pos	search_p(char **map)
{
	t_pos	begin;

	begin.y = 0;
	begin.x = 0;
	while (map[begin.y])
	{
		begin.x = 0;
		while (map[begin.y][begin.x])
		{
			if (map[begin.y][begin.x] == 'P')
				return (begin);
			begin.x++;
		}
		begin.y++;
	}
	return (begin);
}

void	fillmap(char **map, t_pos size, t_pos start)
{
	if (start.y <= 0 || start.y >= size.y || start.x <= 0 || start.x >= size.x
		|| map[start.y][start.x] == '1' || map[start.y][start.x] == 'F'
			|| map[start.y][start.x] == 'X')
		return ;
	map[start.y][start.x] = 'F';
	fillmap(map, size, (t_pos){start.y + 1, start.x});
	fillmap(map, size, (t_pos){start.y - 1, start.x});
	fillmap(map, size, (t_pos){start.y, start.x + 1});
	fillmap(map, size, (t_pos){start.y, start.x - 1});
}

void	counter(char **cpymap, t_player count)
{
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	while (cpymap[i])
	{
		pos = 0;
		while (cpymap[i][pos] && cpymap[i][pos] != '\n')
		{
			if (cpymap[i][pos] == 'P')
				(*count.p)++;
			else if (cpymap[i][pos] == 'C')
				(*count.c)++;
			else if (cpymap[i][pos] == 'E')
				(*count.e)++;
			pos++;
		}
		i++;
	}
}
