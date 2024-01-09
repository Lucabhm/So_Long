/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:23:07 by lbohm             #+#    #+#             */
/*   Updated: 2023/12/14 11:24:26 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <fcntl.h>
# include "../lib/get_next_line/get_next_line.h"
# include "../lib/libft/libft.h"
# include "../lib/printf/ft_printf.h"
# include "../lib/mlx/include/MLX42/MLX42.h"

# define SIZE 12
# define DINO 0
# define GRASS 1
# define ROCK 2
# define STEAK 3
# define CAVE 4
# define BANR 5
# define BANM 6
# define BANL 7
# define BANWR 8
# define BANWM 9
# define BANWL 10
# define METEOR 11

typedef struct s_pos
{
	int32_t	y;
	int32_t	x;
}				t_pos;

typedef struct s_player
{
	int	*p;
	int	*c;
	int	*e;
}				t_player;

typedef struct s_data
{
	mlx_t			*mptr;
	mlx_texture_t	*text[SIZE];
	mlx_image_t		*img[SIZE];
	char			**map;
	t_pos			s;
	int32_t			x;
	int32_t			y;
	int				countc;
	int				c_all;
	int				countermoves;
	int				checkban;
	int				checkcount;
	int32_t			**xenemy;
	int32_t			**yenemy;
	int				rlud;
	int				xcount;
	int				disable;
}				t_data;

char	**start(int argc, char **argv);
char	**creatmap(char **argv);
int		countrows(int fd);
void	checkmap(char **map);
t_pos	sizemap(char **map);
void	errorcounter(t_player count);
int		rowlen(char *str);
void	checkpath(char **map, t_pos size, t_player count);
t_pos	search_p(char **map);
char	**dupmap(char **map, t_pos size);
int		freearr(char **cpyarr);
void	fillmap(char **map, t_pos size, t_pos start);
void	error(int i);
void	checker(char **map, t_player count, t_pos size);
void	checkerinside(char **map, char letter, t_player count);
void	checker_n_and_r(char **map);
void	counter(char **cpymap, t_player count);
void	images(t_data *data);
void	wall_and_ground(t_data *d);
void	p_c_and_e(t_data *d);
int		checkup(void *param);
int		checkdown(void *param);
int		checkleft(void *param);
int		checkright(void *param);
void	key(mlx_key_data_t code, void *param);
void	checkinstance(t_data *mlx);
void	checkpce(t_data *d, int i, int pos);
void	check_e_and_c(t_data *mlx);
void	printbanner(t_data *mlx);
void	freeall(t_data *mlx);
void	biggerfive(t_data *mlx, int pos);
void	lowerfive(t_data *mlx, int pos);
void	biggerten(t_data *mlx, int pos);
void	errormap(int i, char **map);
void	enemy(void *mlx);
void	mallocx(t_data *mlx);
void	checkinstancemeteor(t_data *mlx);
void	string(t_data *mlx, char *checkcount, char *countermove);
void	endscreen(t_data *mlx, int wd);
int		enemyleftup(t_data *mlx, t_pos *p, t_pos *e, int i);
int		enemyrightdown(t_data *mlx, t_pos *p, t_pos *e, int i);
int		catchpy(t_pos *p, t_pos *e, int y);
int		catchpx(t_pos *p, t_pos *e, int x);
void	checkx(t_data *mlx, t_pos *e);
void	endstring(t_data *mlx, int wd);

#endif