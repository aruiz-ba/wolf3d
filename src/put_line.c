/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 17:18:00 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/09/25 20:48:51 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	put_line(int x, int start, int end, t_mlx *mlx)
{
	int	y;
	int	mapy;
	int	color;
	int	st;
	int en;


	mlx->ry.wallh /= 2;
	st = (WIN_HEIGHT/2) - mlx->ry.wallh;
	en = (WIN_HEIGHT/2) + mlx->ry.wallh;
	y = start;
	while(y < end)
	{
		mapy = map2(y, st, en, 0, 64);
		color = mlx->pix[mlx->ry.texX][mapy];
		if(mlx->ry.side == 1)
			color = (color >> 1) & 8355711;
		mlx->map.grid[x][y] = color;
		y++;
	}
}
