/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:11:23 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/09/19 14:51:17 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	text_to_pixel(t_mlx *mlx)
{
	int		x;
	int		y;
	int		pixval;

	y = 0;
	x = 0;

	mlx->min_k = 0;
	while (y < 64)
	{
		x = 0;
		while (x < 64)
		{
			pixval = (mlx->tex.ptr)[mlx->min_k + 0]<<16 | (mlx->tex.ptr)[mlx->min_k + 1]<<8 | (mlx->tex.ptr)[mlx->min_k + 2];
			mlx->pix[x][y] = pixval;
			mlx->min_k += 4;
			x++;
			//printf("color:%X\n", mlx->pix[x][y]);
		}
		y++;
	}
}

void	fill_image_texture(t_mlx	*mlx)
{
	int		x;
	int		y;
	int		tex_k;
	int		tmtex_k;

	y = 0;
	x = 0;
	mlx->min_k = 0;
	tex_k = 0;
	tmtex_k = 0;
	while (y < 64*8)
	{
		x = 0;
		while (x < 64*8)
		{
			(mlx->img.ptr)[mlx->min_k + 0] = mlx->tex.ptr[tex_k + 0];//mlx->pix[x][y] % 256 % 256;
			(mlx->img.ptr)[mlx->min_k + 1] = mlx->tex.ptr[tex_k + 1];//mlx->pix[x][y] / 256 % 256;
			(mlx->img.ptr)[mlx->min_k + 2] = mlx->tex.ptr[tex_k + 2];//mlx->pix[x][y] / 256 / 256;
			(mlx->img.ptr)[mlx->min_k + 3] = 0;
			mlx->min_k += 4;
			if(x%8 == 0)
				tex_k += 4;
			x++;
		}
		if(y%8 == 0)
			tmtex_k = tex_k;
		else
			tex_k = tmtex_k;
		mlx->min_k += (WIN_WIDTH * 4) - (64*4)*8;
		y++;
	}
}

void	load_textures(t_mlx	*mlx)
{
	int		a;
	int		b;

	a = 64;
	b = 64;
	mlx->tex.image = mlx_xpm_file_to_image(mlx->mlx, "textures/stone.xpm", &a, &b);
	mlx->tex.ptr = mlx_get_data_addr(mlx->tex.image, &mlx->tex.bpp,
			&mlx->tex.stride, &mlx->tex.endian);
}
