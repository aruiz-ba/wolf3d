/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 17:18:00 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/11/01 17:00:51 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "stdio.h"

void	put_line(int x, int start, int end, t_mlx *mlx)
{
	t_map2	mp;
	int		mapy;
	int		i;
	int		color;

	mlx->ry.wallh /= 2;
	mp.a0 = (WIN_HEIGHT / 2) - mlx->ry.wallh;
	mp.a1 = (WIN_HEIGHT / 2) + mlx->ry.wallh;
	mp.a = start;
	mp.b0 = 0;
	mp.b1 = 64;
	i = 0;
	while ((int)mp.a < end)
	{
		mapy = map2(&mp);
		if (mlx->ry.side == 0 && mlx->ry.stepx > 0)
			color = mlx->tex[0].pix[mlx->ry.texx][mapy];
		else if (mlx->ry.side == 0 && mlx->ry.stepx < 0)
			color = mlx->tex[1].pix[mlx->ry.texx][mapy];
		else if (mlx->ry.side == 1 && mlx->ry.stepy > 0)
			color = mlx->tex[2].pix[mlx->ry.texx][mapy];
		else if (mlx->ry.side == 1 && mlx->ry.stepy < 0)
			color = mlx->tex[3].pix[mlx->ry.texx][mapy];
		mlx->map.grid[x][(int)mp.a] = color;
		mp.a++;
	}
	while (i < start)
	{
		mlx->map.grid[x][i] = 0x38b0de;
		i++;
	}
	while (mp.a < WIN_HEIGHT)
	{
		mlx->map.grid[x][(int)mp.a] = 0x2f312b;	
		mp.a++;
	}
}
