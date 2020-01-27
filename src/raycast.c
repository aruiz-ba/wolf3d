/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 16:37:23 by aruiz-ba          #+#    #+#             */
/*   Updated: 2020/01/27 17:16:30 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

/*
** Checks when vector gets to a wall
*/

void		raycast_hit_loop(t_mlx *mlx)
{
	while (mlx->rl.hit == 0)
	{
		if (mlx->rl.sidedistx < mlx->rl.sidedisty)
		{
			mlx->rl.sidedistx += mlx->rl.deltadistx;
			mlx->rl.mapx += mlx->ry.stepx;
			mlx->rl.side = 0;
		}
		else
		{
			mlx->rl.sidedisty += mlx->rl.deltadisty;
			mlx->rl.mapy += mlx->ry.stepy;
			mlx->rl.side = 1;
		}
		if (mlx->ry.worldmap[mlx->rl.mapx][mlx->rl.mapy] == 1)
			mlx->rl.hit = 1;
	}
	if (mlx->rl.side == 0)
		mlx->rl.perpwalldist = (mlx->rl.mapx - mlx->ry.posx
			+ (1 - mlx->ry.stepx) / 2) / mlx->rl.raydirx;
	else
		mlx->rl.perpwalldist = (mlx->rl.mapy - mlx->ry.posy
			+ (1 - mlx->ry.stepy) / 2) / mlx->rl.raydiry;
}

void		sub_raycast_loop(t_mlx *mlx)
{
	if (mlx->rl.raydirx < 0)
	{
		mlx->ry.stepx = -1;
		mlx->rl.sidedistx = (mlx->ry.posx - mlx->rl.mapx)
			* mlx->rl.deltadistx;
	}
	else
	{
		mlx->ry.stepx = 1;
		mlx->rl.sidedistx = (mlx->rl.mapx + 1.0 - mlx->ry.posx)
			* mlx->rl.deltadistx;
	}
	if (mlx->rl.raydiry < 0)
	{
		mlx->ry.stepy = -1;
		mlx->rl.sidedisty = (mlx->ry.posy - mlx->rl.mapy)
			* mlx->rl.deltadisty;
	}
	else
	{
		mlx->ry.stepy = 1;
		mlx->rl.sidedisty = (mlx->rl.mapy + 1.0 - mlx->ry.posy)
			* mlx->rl.deltadisty;
	}
}

void		set_raycast_var(t_mlx *mlx)
{
	mlx->rl.camerax = 2 * mlx->rl.x / (double)(WIN_WIDTH) - 1;
	mlx->rl.raydirx = mlx->ry.dirx + mlx->ry.planex * mlx->rl.camerax;
	mlx->rl.raydiry = mlx->ry.diry + mlx->ry.planey * mlx->rl.camerax;
	mlx->rl.mapx = (int)(mlx->ry.posx);
	mlx->rl.mapy = (int)(mlx->ry.posy);
	mlx->rl.deltadistx = fabs(1 / mlx->rl.raydirx);
	mlx->rl.deltadisty = fabs(1 / mlx->rl.raydiry);
	mlx->rl.hit = 0;
}

/*
** functiont loop: calculate distance to proyect wall on each column of pixels
*/

void		raycast_loop(t_mlx *mlx)
{
	mlx->rl.x = -1;
	while (++mlx->rl.x < WIN_WIDTH)
	{
		set_raycast_var(mlx);
		sub_raycast_loop(mlx);
		raycast_hit_loop(mlx);
		mlx->rl.lineheight = (int)(WIN_HEIGHT / mlx->rl.perpwalldist);
		mlx->rl.drawstart = (-mlx->rl.lineheight / 2) + (WIN_HEIGHT / 2);
		if (mlx->rl.drawstart < 0)
			mlx->rl.drawstart = 0;
		mlx->rl.drawend = (mlx->rl.lineheight / 2) + (WIN_HEIGHT / 2);
		if (mlx->rl.drawend >= WIN_HEIGHT)
			mlx->rl.drawend = WIN_HEIGHT - 1;
		if (mlx->rl.side == 1)
			mlx->map.color /= 2;
		if (mlx->rl.side == 0)
			mlx->rl.wallx = mlx->ry.posy + mlx->rl.perpwalldist
				* mlx->rl.raydiry;
		else
			mlx->rl.wallx = mlx->ry.posx + mlx->rl.perpwalldist
				* mlx->rl.raydirx;
		set_putline_var(mlx);
		put_line(mlx->rl.x, mlx->rl.drawstart, mlx->rl.drawend, mlx);
	}
}

/*
** Set all the function variables
*/

void		raycast(t_mlx *mlx)
{
	double	x;
	double	y;
	double	xp;
	double	yp;

	x = -1;
	y = 0;
	xp = 0;
	yp = 0.66;
	mlx->ry.posx = mlx->posx;
	mlx->ry.posy = mlx->posy;
	mlx->ry.dirx = (x * cos(mlx->rot)) - (y * sin(mlx->rot));
	mlx->ry.diry = (x * sin(mlx->rot)) + (y * cos(mlx->rot));
	mlx->ry.planex = (xp * cos(mlx->rot)) - (yp * sin(mlx->rot));
	mlx->ry.planey = (xp * sin(mlx->rot)) + (yp * cos(mlx->rot));
	raycast_loop(mlx);
}
