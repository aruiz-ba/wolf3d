/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 14:02:24 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/11/05 15:29:19 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		freegrid(t_map *map)
{
	int		i;
	int		j;

	i = -1;
	while (++i < WIN_HEIGHT)
	{
		j = -1;
		while (++j < WIN_WIDTH)
			map->grid[j][i] = 0x00000;
	}
}

void		freeimage(char **image_string)
{
	int		i;
	int		k;
	int		color;

	color = 0xFFFFFF;
	k = 0;
	i = -1;
	while (++i < (WIN_HEIGHT * WIN_WIDTH))
	{
		(*image_string)[k + 0] = (char)(color % 256 % 256);
		(*image_string)[k + 1] = (char)(color / 256 % 256);
		(*image_string)[k + 2] = (char)(color / 256 / 256);
		(*image_string)[k + 3] = 0;
		k += 4;
	}
}

void		fill_image(t_mlx *mlx)
{
	int		x;
	int		y;
	int		k;

	y = -1;
	k = 0;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
		{
			(mlx->img.ptr)[k + 0] = mlx->map.grid[x][y] % 256 % 256;
			(mlx->img.ptr)[k + 1] = mlx->map.grid[x][y] / 256 % 256;
			(mlx->img.ptr)[k + 2] = mlx->map.grid[x][y] / 256 / 256;
			(mlx->img.ptr)[k + 3] = 0;
			k += 4;
		}
	}
}
