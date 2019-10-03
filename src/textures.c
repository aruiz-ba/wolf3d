/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:11:23 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/10/03 20:38:29 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	text_to_pixel(t_mlx *mlx)
{
	int				x;
	int				y;
	int				i;
	int				min_k;
	int				pixval;

	y = 0;
	x = 0;
	i = 0;

	min_k = 0;
	while(i <= 3)//num of textures
	{
		y = 0;
		min_k = 0;
		while (y < 64)
		{
			x = 0;
			while (x < 64)
			{
				pixval =  (((mlx->tex[i].ptr)[min_k + 3] & 0xff) << 24) + (((mlx->tex[i].ptr)[min_k + 2] & 0xff) << 16) + (((mlx->tex[i].ptr)[min_k + 1] & 0xff) << 8) + ((mlx->tex[i].ptr)[min_k + 0] & 0xff);
				mlx->tex[i].pix[x][y] = pixval;
				min_k += 4;
				x++;
			}
			y++;
		}
		i++;
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
			(mlx->img.ptr)[mlx->min_k + 0] = mlx->tex[3].pix[tx_x][tx_y] % 256 % 256;
			(mlx->img.ptr)[mlx->min_k + 1] = mlx->tex[3].pix[tx_x][tx_y] / 256 % 256;
			(mlx->img.ptr)[mlx->min_k + 2] = mlx->tex[3].pix[tx_x][tx_y] / 256 / 256;
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
	int		i;

	a = 64;
	b = 64;
	i = 0;
	while(i <= 3)
	{
		if(i == 0)
			mlx->tex[i].image = mlx_xpm_file_to_image(mlx->mlx, "textures/cobble.xpm", &a, &b);
		if(i == 1)
			mlx->tex[i].image = mlx_xpm_file_to_image(mlx->mlx, "textures/stone.xpm", &a, &b);
		if(i == 2)
			mlx->tex[i].image = mlx_xpm_file_to_image(mlx->mlx, "textures/wood.xpm", &a, &b);
		if(i == 3)
			mlx->tex[i].image = mlx_xpm_file_to_image(mlx->mlx, "textures/woodor.xpm", &a, &b);
		mlx->tex[i].ptr = mlx_get_data_addr(mlx->tex[i].image, &mlx->tex[i].bpp,
		&mlx->tex[i].stride, &mlx->tex[i].endian);
		i++;
	}
}
