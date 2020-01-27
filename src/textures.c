/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:11:23 by aruiz-ba          #+#    #+#             */
/*   Updated: 2020/01/27 16:10:30 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

/*
** Codes each pixel to print textures to the walls
*/

void	sky_to_pixel(t_mlx *mlx)
{
	int	x;
	int	y;
	int	i;
	int	k;

	i = -1;
	while (++i <= 3)
	{
		y = -1;
		k = 0;
		while (++y < 720)
		{
			x = -1;
			while (++x < 1080)
			{
				mlx->skyimg.pix[x][y] =
					(((mlx->skyimg.ptr)[k + 3] & 0xff) << 24) +
					(((mlx->skyimg.ptr)[k + 2] & 0xff) << 16) +
					(((mlx->skyimg.ptr)[k + 1] & 0xff) << 8) +
					((mlx->skyimg.ptr)[k + 0] & 0xff);
				k += 4;
			}
		}
	}
}

void	text_to_pixel(t_mlx *mlx)
{
	int	x;
	int	y;
	int	i;
	int	k;

	i = -1;
	while (++i <= 3)
	{
		y = -1;
		k = 0;
		while (++y < 64)
		{
			x = -1;
			while (++x < 64)
			{
				mlx->tex[i].pix[x][y] =
					(((mlx->tex[i].ptr)[k + 3] & 0xff) << 24) +
					(((mlx->tex[i].ptr)[k + 2] & 0xff) << 16) +
					(((mlx->tex[i].ptr)[k + 1] & 0xff) << 8) +
					((mlx->tex[i].ptr)[k + 0] & 0xff);
				k += 4;
			}
		}
	}
	sky_to_pixel(mlx);
}

/*
** Loads the textures in the array mlx->tex[i], from i = 0 to i = 3,
** one value for each orientation of the wall
*/

void	xpm_to_image(t_mlx *mlx, int i, int a)
{
	int	y;
	int	x;

	x = 1080;
	y = 720;
	if (i == 0)
		mlx->tex[i].image = mlx_xpm_file_to_image(mlx->mlx,
				"textures/prismarine.xpm", &a, &a);
	if (i == 1)
		mlx->tex[i].image = mlx_xpm_file_to_image(mlx->mlx,
				"textures/nether_bricks.xpm", &a, &a);
	if (i == 2)
		mlx->tex[i].image = mlx_xpm_file_to_image(mlx->mlx,
				"textures/stone_bricks.xpm", &a, &a);
	if (i == 3)
		mlx->tex[i].image = mlx_xpm_file_to_image(mlx->mlx,
				"textures/obsidian.xpm", &a, &a);
	if (i == 4)
	{
		mlx->skyimg.image = mlx_xpm_file_to_image(mlx->mlx,
				"textures/sky.xpm", &x, &y);
		mlx->skyimg.ptr = mlx_get_data_addr(mlx->skyimg.image,
			&mlx->skyimg.bpp, &mlx->skyimg.stride, &mlx->skyimg.endian);
	}
}

int		check_resource(void)
{
	if (open("textures/prismarine.xpm", O_RDONLY | O_NOFOLLOW) == -1 ||
			open("textures/nether_bricks.xpm", O_RDONLY | O_NOFOLLOW) == -1 ||
			open("textures/stone_bricks.xpm", O_RDONLY | O_NOFOLLOW) == -1 ||
			open("textures/obsidian.xpm", O_RDONLY | O_NOFOLLOW) == -1 ||
			open("textures/sky.xpm", O_RDONLY | O_NOFOLLOW) == -1)
		return (-1);
	else
		return (0);
}

void	load_textures(t_mlx *mlx)
{
	int	i;
	int	a;

	i = 0;
	a = 64;
	if (check_resource() == -1)
		error(3);
	while (i <= 4)
	{
		xpm_to_image(mlx, i, a);
		mlx->tex[i].ptr = mlx_get_data_addr(mlx->tex[i].image,
				&mlx->tex[i].bpp, &mlx->tex[i].stride, &mlx->tex[i].endian);
		i++;
	}
}
