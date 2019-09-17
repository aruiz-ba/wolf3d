/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:11:23 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/09/17 19:19:15 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	text_to_pixel(t_mlx *mlx)
{
	int		x;
	int		y;
	int		pixval;

	y = mlx->y;
	x = mlx->x;
	while (mlx->y < (64 + y))
	{
		mlx->x = x;
		while (mlx->x < (64 + x))
		{
			//		(mlx->img.ptr)[mlx->min_k + 0] = mlx->map.grid[mlx->x][mlx->y] % 256 % 256;
			//		(mlx->img.ptr)[mlx->min_k + 1] = mlx->map.grid[mlx->x][mlx->y] / 256 % 256;
			//		(mlx->img.ptr)[mlx->min_k + 2] = mlx->map.grid[mlx->x][mlx->y] / 256 / 256;
			//		(mlx->img.ptr)[mlx->min_k + 3] = 0;
			//		mlx->min_k += 4;
			//		mlx->x++;
			pixval = (mlx->tex.ptr)[mlx->min_k + 0] ;
			mlx->pix[x][y] = pixval;
		}
		mlx->y++;
	}
}

void	load_textures(t_mlx	*mlx)
{
	int		a;
	int		b;

	a = 64;
	b = 64;
	mlx->tex.image = mlx_xpm_file_to_image(mlx->mlx, "textures/wood.xpm", &a, &b);
	mlx->tex.ptr = mlx_get_data_addr(mlx->tex.image, &mlx->tex.bpp,
			&mlx->tex.stride, &mlx->tex.endian);
}
