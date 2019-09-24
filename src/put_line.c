/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 17:18:00 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/09/24 19:09:46 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	put_line(int start,int  end, t_mlx *mlx)
{
	int	d;
	int	y;
	int	mapx;
	int	texY;
	int	color;
	
	y = start;
	mapx = map2(mlx->ry.x, 0 ,WIN_WIDTH, 0, 64);
	while(y < end)
	{
		d = y * 256 - WIN_HEIGHT * 128 + mlx->ry.lineHeight * 128;
		texY = ((d * texHeight) / mlx->ry.lineHeight) / 256;
		color = mlx->pix[mapx][texHeight * texY + mlx->ry.texX];
		if(mlx->ry.side == 1)
			color = (color >> 1) & 8355711;
		mlx->map.grid[mlx->ry.x][y] = color;
		y++;
	}
}
