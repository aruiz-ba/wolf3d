/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 16:37:23 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/10/14 18:26:19 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	set_color(int	i, t_map *map)
{
	if (i == 1)
		map->color = RGB_Red;
	if (i == 2)
		map->color = RGB_Green;
	if (i == 3)
		map->color = RGB_Blue;
	if (i == 4)
		map->color = RGB_White;
	if (i > 4)
		map->color = RGB_Yellow;
}

void	raycast_loop(t_mlx *mlx)
{
	int		x;
	double	sideDistX;
	double	sideDistY;

	double	perpWallDist;

	int		hit;

	x = -1;
	while (++x < WIN_WIDTH)
	{
		double	cameraX = 2 * x / (double)(WIN_WIDTH) - 1; //check this out
		double	rayDirX = mlx->ry.dirX + mlx->ry.planeX * cameraX;
		double	rayDirY = mlx->ry.dirY + mlx->ry.planeY * cameraX;
		
		int		mapX = (int)(mlx->ry.posX);
		int		mapY = (int)(mlx->ry.posY);
		
		double	deltaDistX = fabs(1 / rayDirX);
		double	deltaDistY = fabs(1 / rayDirY);

		int		side;

		hit	= 0;
		
		if (rayDirX < 0)	
		{
			mlx->ry.stepX = -1;
			sideDistX = (mlx->ry.posX - mapX) * deltaDistX;
		}
		else
		{
			mlx->ry.stepX = 1;
			sideDistX = (mapX + 1.0 - mlx->ry.posX) * deltaDistX;
		}
		if (rayDirY < 0)	
		{
			mlx->ry.stepY = -1;
			sideDistY = (mlx->ry.posY - mapY) * deltaDistY;
		}
		else
		{
			mlx->ry.stepY = 1;
			sideDistY = (mapY + 1.0 - mlx->ry.posY) * deltaDistY;
		}
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX	+= mlx->ry.stepX;
				side	= 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += mlx->ry.stepY;
				side = 1;
			}
			if (mlx->ry.worldMap[mapX][mapY] == 1)
				hit = 1;
		}
		if (side == 0)
			perpWallDist = (mapX - mlx->ry.posX + (1 - mlx->ry.stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - mlx->ry.posY + (1 - mlx->ry.stepY) / 2) / rayDirY;
		int lineHeight = (int)(WIN_HEIGHT / perpWallDist);

		int	drawStart = (-lineHeight / 2) + (WIN_HEIGHT / 2);
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = (lineHeight / 2) + (WIN_HEIGHT / 2);
		if (drawEnd >= WIN_HEIGHT)
			drawEnd = WIN_HEIGHT - 1;
	//	set_color(mlx->ry.worldMap[mapX][mapY], &mlx->map);
		if (side == 1)
			mlx->map.color /= 2;


		double wallX;	//where exacly wall was hit

		if (side == 0)
			wallX = mlx->ry.posY + perpWallDist * rayDirY;
		else
			wallX = mlx->ry.posX + perpWallDist * rayDirX;
		wallX -= floor(wallX);
		//xcordinate on the texture
		int texX;

		texX = (int)(wallX * (double)texWidth);
		if (side == 0 && rayDirX > 0)
			texX = texWidth - texX - 1;
		if (side == 1 && rayDirY < 0)
			texX = texWidth - texX -1;
		mlx->ry.lineHeight = lineHeight;
		mlx->ry.texX = texX;
		mlx->ry.x = x;
		mlx->ry.side = side;
		mlx->ry.wallX = wallX;
		mlx->ry.wallh = lineHeight;
		put_line(x, drawStart, drawEnd, mlx);
	}
}

void	raycast(t_mlx *mlx)
{
	double		x;
	double		y;
	double		xp;
	double		yp;

	x = -1;
	y = 0;
	xp = 0;
	yp = 0.66;
	mlx->ry.posX = mlx->posX;
	mlx->ry.posY = mlx->posY;
	mlx->ry.dirX = (x * cos(mlx->rot)) - (y * sin(mlx->rot));
	mlx->ry.dirY = (x * sin(mlx->rot)) + (y * cos(mlx->rot));
	mlx->ry.planeX = (xp * cos(mlx->rot)) - (yp * sin(mlx->rot));
	mlx->ry.planeY = (xp * sin(mlx->rot)) + (yp * cos(mlx->rot));
	raycast_loop(mlx);
}
