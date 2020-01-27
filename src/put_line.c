/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 17:18:00 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/11/11 16:11:33 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		put_line_no_textures(int x, int start, int end, t_mlx *mlx)
{
	int		color;

	while (start < end)
	{
		if (mlx->ry.side == 0 && mlx->ry.stepx > 0)
			color = RGB_RED;
		else if (mlx->ry.side == 0 && mlx->ry.stepx < 0)
			color = RGB_GREEN;
		else if (mlx->ry.side == 1 && mlx->ry.stepy > 0)
			color = RGB_BLUE;
		else if (mlx->ry.side == 1 && mlx->ry.stepy < 0)
			color = RGB_WHITE;
		mlx->map.grid[x][start] = color;
		start++;
	}
}

void		sub_put_line(int x, int start, t_map2 *mp, t_mlx *mlx)
{
	int		i;

	i = -1;
	while (++i < start)
		mlx->map.grid[x][i] = mlx->skyimg.pix[x][i];
	while (mp->a++ < WIN_HEIGHT)
		mlx->map.grid[x][(int)mp->a] = mlx->skyimg.pix[x][WIN_HEIGHT / 2];
}

void		set_map_struct(t_map2 *mp, t_mlx *mlx, int start)
{
	mlx->ry.wallh /= 2;
	mp->a0 = (WIN_HEIGHT / 2) - mlx->ry.wallh;
	mp->a1 = (WIN_HEIGHT / 2) + mlx->ry.wallh;
	mp->a = start;
	mp->b0 = 0;
	mp->b1 = 64;
}

void		put_line(int x, int start, int end, t_mlx *mlx)
{
	t_map2	mp;
	int		mapy;
	int		color;

	if (mlx->spacebar == 1)
	{
		set_map_struct(&mp, mlx, start);
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
		sub_put_line(x, start, &mp, mlx);
	}
	else
		put_line_no_textures(x, start, end, mlx);
}
