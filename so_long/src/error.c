/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:07:34 by lucabhm           #+#    #+#             */
/*   Updated: 2023/12/14 10:32:56 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	errorcounter(t_player count)
{
	if (*count.p != 1)
		ft_printf("ERROR:\nToo many players or none available!\n");
	if (*count.c == 0)
		ft_printf("ERROR:\nNo Collectable present!\n");
	if (*count.e != 1)
		ft_printf("ERROR:\nToo many or no exits!\n");
	exit(0);
}

void	error(int i)
{
	if (i == 0)
		ft_printf("ERROR:\nFile not end with .ber!\n");
	if (i == 1)
		ft_printf("ERROR:\nFile is empty or only one line!\n");
	if (i == 8)
		ft_printf("ERROR:\nMap is too small for a valid path!");
	if (i == 9)
		ft_printf("ERROR:\nAllocation fails doublepointer\n");
	if (i == 10)
		ft_printf("ERROR:Allocation fails string\n");
	if (i == 11)
		ft_printf("ERROR:\nToo few arguments!\n");
	if (i > 11)
		ft_printf("ERROR:\nToo many arguments!\n");
	exit(0);
}

void	errormap(int i, char **map)
{
	if (i == 3)
		ft_printf("ERROR:\nMap contains an empty line!\n");
	if (i == 4)
		ft_printf("ERROR:\nMap is not a rectangle!\n");
	if (i == 5)
		ft_printf("ERROR:\nThe map must be closed/surrounded by walls!\n");
	if (i == 6)
		ft_printf("ERROR:\nNon-valid character inside!\n");
	if (i == 7)
		ft_printf("ERROR:\nNo possible path found!\n");
	freearr(map);
	exit(0);
}
