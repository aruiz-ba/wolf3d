/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:45:02 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/10/10 19:10:19 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	test_board(t_mlx *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	//mlx->ry.worldMap[][];
	//h and w;
	while(y < mlx->ry.mapHeight)
	{
		while(x < mlx->ry.mapWidth)
		{
			if(mlx->ry.worldMap[0][x] != 1)
				return(0);
			if(mlx->ry.worldMap[mlx->ry.mapHeight - 1][x] != 1)
				return(0);
			x++;	
		}
		x = 0;
		if(mlx->ry.worldMap[y][0] != 1)
			return(0);
		if(mlx->ry.worldMap[y][mlx->ry.mapHeight - 1] != 1)
			return(0);
		y++;
	}
	return(1);
}
