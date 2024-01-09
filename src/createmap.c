/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:32:15 by lbohm             #+#    #+#             */
/*   Updated: 2023/12/14 10:32:44 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**start(int argc, char **argv)
{
	char	**map;

	if (argc == 2)
	{
		if (!(ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]))))
			error(0);
		map = creatmap(argv);
		checkmap(map);
		return (map);
	}
	else
		error(argc + 10);
	return (NULL);
}

char	**creatmap(char **argv)
{
	int		fd;
	int		rows;
	char	**map;
	int		i;

	fd = 0;
	rows = 0;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	rows = countrows(fd);
	close(fd);
	if (rows == 1)
		error(1);
	if (rows == 2)
		error(8);
	fd = open(argv[1], O_RDONLY);
	map = (char **)malloc ((rows + 1) * sizeof(char *));
	if (!(map))
		error(9);
	while (rows > i)
		map[i++] = get_next_line(fd);
	map[i] = NULL;
	close(fd);
	return (map);
}

int	countrows(int fd)
{
	char	*newline;
	int		rows;
	int		byt_size;
	int		pos;

	rows = 0;
	byt_size = 1;
	newline = (char *)malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!(newline))
		error(10);
	while (byt_size > 0)
	{
		pos = -1;
		byt_size = read(fd, newline, BUFFER_SIZE);
		if (byt_size <= 0)
			break ;
		newline[byt_size] = '\0';
		while (newline[++pos])
		{
			if (newline[pos] == '\n')
				rows++;
		}
	}
	free(newline);
	return (rows + 1);
}
