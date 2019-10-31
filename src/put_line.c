/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 17:18:00 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/10/31 15:12:46 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	put_line(int x, int start, int end, t_mlx *mlx)
{
	t_map2	mp;
	int		mapy;
	int		color;

	mlx->ry.wallh /= 2;
	mp.a0 = (WIN_HEIGHT / 2) - mlx->ry.wallh;
	mp.a1 = (WIN_HEIGHT / 2) + mlx->ry.wallh;
	mp.a = start;
	mp.b0 = 0;
	mp.b1 = 64;
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
}
