/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:52:36 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/10/14 19:34:13 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	get_player_pos(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while(y < mlx->ry.mapHeight)
	{
		x = 0;
		while(x < mlx->ry.mapWidth)
		{
			if(mlx->ry.worldMap[y][x] == 2)
			{
				mlx->posX = y;
				mlx->posY = x;
				return(1);
			}
			x++;
		}
		y++;
	}
	return(0);
}
