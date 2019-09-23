/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:11:23 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/09/23 19:23:55 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	text_to_pixel(t_mlx *mlx)
{
	int				x;
	int				y;
	int				pixval;

	y = 0;
	x = 0;

	mlx->min_k = 0;
	while (y < 64)
	{
		x = 0;
		while (x < 64)
		{
		//	pixval = (mlx->tex.ptr)[mlx->min_k + 0]<<16 | (mlx->tex.ptr)[mlx->min_k + 1]<<8 | (mlx->tex.ptr)[mlx->min_k + 2];
			pixval =  (((mlx->tex.ptr)[mlx->min_k + 3] & 0xff) << 24) + (((mlx->tex.ptr)[mlx->min_k + 2] & 0xff) << 16) + (((mlx->tex.ptr)[mlx->min_k + 1] & 0xff) << 8) + ((mlx->tex.ptr)[mlx->min_k + 0] & 0xff);
			mlx->map.pix[x][y] = pixval;
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
	int		tx_x;
	int		tx_y;
	int		tmtx_y;

	y = 0;
	x = 0;
	mlx->min_k = 0;
	tx_x = 0;
	tx_y = 0;	
	tmtx_y = 0;
	while (y < 64*8)
	{
		x = 0;
		tx_x = 0;
		while (x < 64*8)
		{
			(mlx->img.ptr)[mlx->min_k + 0] = mlx->map.pix[tx_x][tx_y] % 256 % 256;
			(mlx->img.ptr)[mlx->min_k + 1] = mlx->map.pix[tx_x][tx_y] / 256 % 256;
			(mlx->img.ptr)[mlx->min_k + 2] = mlx->map.pix[tx_x][tx_y] / 256 / 256;
			(mlx->img.ptr)[mlx->min_k + 3] = 0;
			mlx->min_k += 4;
			if(x%8 == 0)
				tx_x++;
			x++;
		}
		if(y%8 == 0)
		{
			tx_y++;
			tmtx_y = tx_y;
		}
		else
			tx_y = tmtx_y;
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
