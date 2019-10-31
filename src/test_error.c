/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:45:02 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/10/31 15:20:05 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	test_board(t_mlx *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < mlx->ry.mapheight)
	{
		while (x < mlx->ry.mapwidth)
		{
			if (mlx->ry.worldmap[0][x] != 1)
				return (0);
			if (mlx->ry.worldmap[mlx->ry.mapheight - 1][x] != 1)
				return (0);
			x++;
		}
		x = 0;
		if (mlx->ry.worldmap[y][0] != 1)
			return (0);
		if (mlx->ry.worldmap[y][mlx->ry.mapwidth - 1] != 1)
			return (0);
		y++;
	}
	return (1);
}
