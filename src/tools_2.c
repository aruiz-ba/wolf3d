/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:52:36 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/11/11 16:48:10 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		set_putline_var(t_mlx *mlx)
{
	mlx->rl.wallx -= floor(mlx->rl.wallx);
	mlx->rl.texx = (int)(mlx->rl.wallx * (double)TEXWIDTH);
	if (mlx->rl.side == 0 && mlx->rl.raydirx > 0)
		mlx->rl.texx = TEXWIDTH - mlx->rl.texx - 1;
	if (mlx->rl.side == 1 && mlx->rl.raydiry < 0)
		mlx->rl.texx = TEXWIDTH - mlx->rl.texx - 1;
	mlx->ry.lineheight = mlx->rl.lineheight;
	mlx->ry.texx = mlx->rl.texx;
	mlx->ry.x = mlx->rl.x;
	mlx->ry.side = mlx->rl.side;
	mlx->ry.wallx = mlx->rl.wallx;
	mlx->ry.wallh = mlx->rl.lineheight;
}

int			digitnum(char const *s)
{
	int		i;
	int		digitnum;

	i = 0;
	digitnum = 0;
	while (s[i])
	{
		if (s[i] != ' ' && (s[i + 1] == ' ' || s[i + 1] == '\0'))
			digitnum++;
		i++;
	}
	return (digitnum);
}

double		map1(double a, double a1, double b0, double b1)
{
	int		a0;

	a0 = 90;
	return (b0 + (b1 - b0) * ((a - a0) / (a1 - a0)));
}

double		map2(t_map2 *mp)
{
	double	i;

	i = (mp->b0 + (mp->b1 - mp->b0) * ((mp->a - mp->a0) / (mp->a1 - mp->a0)));
	return (i);
}

/*
** Writes player position into mlx->posx and posy
*/

int			get_player_pos(t_mlx *mlx)
{
	int		x;
	int		y;

	y = -1;
	while (++y < mlx->ry.mapheight)
	{
		x = -1;
		while (++x < mlx->ry.mapwidth)
		{
			if (mlx->ry.worldmap[y][x] == 2)
			{
				mlx->posx = y + 0.5;
				mlx->posy = x + 0.5;
				return (1);
			}
		}
	}
	return (0);
}
