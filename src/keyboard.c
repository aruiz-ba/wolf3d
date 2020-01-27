/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 14:12:23 by aruiz-ba          #+#    #+#             */
/*   Updated: 2020/01/27 17:15:26 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	move_forward(t_mlx *mlx)
{
	double	i;
	double	b;
	double	xmove;
	double	ymove;

	if (mlx->ry.dirx < 0)
		i = -0.15;
	else
		i = 0.15;
	if (mlx->ry.diry < 0)
		b = -0.15;
	else
		b = 0.15;
	xmove = mlx->ry.dirx * (P_SPEED + mlx->sprint) + i;
	ymove = mlx->ry.diry * (P_SPEED + mlx->sprint) + b;
	if (mlx->ry.worldmap[(int)(mlx->posx + xmove)][(int)mlx->posy] != 1)
		mlx->posx += mlx->ry.dirx * (P_SPEED + mlx->sprint);
	if (mlx->ry.worldmap[(int)mlx->posx][(int)(mlx->posy + ymove)] != 1)
		mlx->posy += mlx->ry.diry * (P_SPEED + mlx->sprint);
}

void	move_backward(t_mlx *mlx)
{
	double	i;
	double	b;
	double	xmove;
	double	ymove;

	if (mlx->ry.dirx < 0)
		i = -0.15;
	else
		i = 0.15;
	if (mlx->ry.diry < 0)
		b = -0.15;
	else
		b = 0.15;
	xmove = mlx->ry.dirx * (P_SPEED + mlx->sprint) + i;
	ymove = mlx->ry.diry * (P_SPEED + mlx->sprint) + b;
	if (mlx->ry.worldmap[(int)(mlx->posx - xmove)][(int)mlx->posy] != 1)
		mlx->posx -= mlx->ry.dirx * (P_SPEED + mlx->sprint);
	if (mlx->ry.worldmap[(int)mlx->posx][(int)(mlx->posy - ymove)] != 1)
		mlx->posy -= mlx->ry.diry * (P_SPEED + mlx->sprint);
}

int		setall(t_mlx *mlx)
{
	if (mlx->move_sprint == 1)
		mlx->sprint = .05;
	else
		mlx->sprint = 0;
	if (mlx->move_right == 1)
		mlx->rot -= 0.05;
	if (mlx->move_left == 1)
		mlx->rot += 0.05;
	if (mlx->move_up == 1)
		move_forward(mlx);
	if (mlx->move_down == 1)
		move_backward(mlx);
	mlx->y = 0;
	mlx->x = 0;
	freeimage(&mlx->img.ptr);
	freegrid(&mlx->map);
	mlx_clear_window(mlx->mlx, mlx->win);
	raycast(mlx);
	fill_image(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.image, 0, 0);
	return (0);
}

int		key_press(int key, t_mlx *mlx)
{
	if (key == 123)
		mlx->move_left = 1;
	if (key == 124)
		mlx->move_right = 1;
	if (key == 126)
		mlx->move_up = 1;
	if (key == 125)
		mlx->move_down = 1;
	if (key == SPACEBAR)
		mlx->spacebar = 0;
	if (key == SHIFT)
		mlx->move_sprint = 1;
	if (key == ESC)
		exit(0);
	return (1);
}

int		key_release(int key, t_mlx *mlx)
{
	if (key == 123)
		mlx->move_left = 0;
	if (key == 124)
		mlx->move_right = 0;
	if (key == 126)
		mlx->move_up = 0;
	if (key == 125)
		mlx->move_down = 0;
	if (key == SPACEBAR)
		mlx->spacebar = 1;
	if (key == SHIFT)
		mlx->move_sprint = 0;
	if (key == ESC)
		exit(0);
	return (1);
}
