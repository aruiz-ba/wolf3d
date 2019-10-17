/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:52:36 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/10/17 19:27:28 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

double	map1(double a, double a1, double b0, double b1)
{
	int		a0;

	a0 = 90;
	return (b0 + (b1 - b0) * ((a - a0) / (a1 - a0)));
}

double	map2(double a, double a0, double a1, double b0, double b1)
{
	return (b0 + (b1 - b0) * ((a - a0) / (a1 - a0)));
}

int	get_player_pos(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < mlx->ry.mapHeight)
	{
		x = 0;
		while (x < mlx->ry.mapWidth)
		{
			if (mlx->ry.worldMap[y][x] == 2)
			{
				mlx->posX = y;
				mlx->posY = x;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
