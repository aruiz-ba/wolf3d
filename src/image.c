/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 14:02:24 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/09/25 14:32:58 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	freegrid(t_map *map)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			map->grid[j][i] = 0x00000;
			j++;
		}
		i++;
	}
}

void	freeimage(char **image_string)
{
	int		i;
	int		k;
	int		color;

	color = 0xFFFFFF;
	k = 0;
	i = 0;
	while (i < (WIN_HEIGHT * WIN_WIDTH))
	{
		(*image_string)[k + 0] = (char)(color % 256 % 256);
		(*image_string)[k + 1] = (char)(color / 256 % 256);
		(*image_string)[k + 2] = (char)(color / 256 / 256);
		(*image_string)[k + 3] = 0;
		k += 4;
		i++;
	}
}

void	fill_image(t_mlx	*mlx)
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			(mlx->img.ptr)[mlx->min_k + 0] = mlx->map.grid[x][y] % 256 % 256;
			(mlx->img.ptr)[mlx->min_k + 1] = mlx->map.grid[x][y] / 256 % 256;
			(mlx->img.ptr)[mlx->min_k + 2] = mlx->map.grid[x][y] / 256 / 256;
			(mlx->img.ptr)[mlx->min_k + 3] = 0;
			mlx->min_k += 4;
			x++;
		}
		y++;
	}
}

void	new_image(t_mlx *mlx)
{
	mlx->img.image = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->img.ptr = mlx_get_data_addr(mlx->img.image, &mlx->img.bpp, &mlx->img.stride,
	&mlx->img.endian);
}
