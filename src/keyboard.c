/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 14:12:23 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/10/24 18:30:55 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	sub_setall_up(t_mlx *mlx)
{
	if (mlx->posX < (mlx->ry.mapHeight / (double)2))
	{
		if (mlx->posX > 1.1 || mlx->ry.dirX > 0)
			mlx->posX += mlx->ry.dirX * (P_SPEED + mlx->sprint);
	}
	else
	{
		if ((mlx->posX < (mlx->ry.mapHeight - 1.1)) || mlx->ry.dirX < 0)
			mlx->posX += mlx->ry.dirX * (P_SPEED + mlx->sprint);
	}
	if (mlx->posY < (mlx->ry.mapWidth / (double)2))
	{
		if (mlx->posY > 1.1 || mlx->ry.dirY > 0)
			mlx->posY += mlx->ry.dirY * (P_SPEED + mlx->sprint);
	}
	else
	{
		if ((mlx->posY < (mlx->ry.mapWidth - 1.1)) || mlx->ry.dirY < 0)
			mlx->posY += mlx->ry.dirY * (P_SPEED + mlx->sprint);
	}
}

void	sub_setall_down(t_mlx *mlx)
{
	if (mlx->posX < (mlx->ry.mapHeight / (double)2))
	{
		if (mlx->posX > 1.1 || mlx->ry.dirX < 0)
			mlx->posX -= mlx->ry.dirX * (P_SPEED + mlx->sprint);
	}
	else
	{
		if ((mlx->posX < (mlx->ry.mapHeight - 1.1)) || mlx->ry.dirX > 0)
			mlx->posX -= mlx->ry.dirX * (P_SPEED + mlx->sprint);
	}
	if (mlx->posY < (mlx->ry.mapWidth / (double)2))
	{
		if (mlx->posY > 1.1 || mlx->ry.dirY < 0)
			mlx->posY -= mlx->ry.dirY * (P_SPEED + mlx->sprint);
	}
	else
	{
		if ((mlx->posY < (mlx->ry.mapWidth - 1.1)) || mlx->ry.dirY > 0)
			mlx->posY -= mlx->ry.dirY * (P_SPEED + mlx->sprint);
	}
}

int		setall(t_mlx *mlx)
{
	if (mlx->move_sprint == 1)
		mlx->sprint = .04;
	else
		mlx->sprint = 0;
	if (mlx->move_right == 1)
		mlx->rot -= 0.05;
	if (mlx->move_left == 1)
		mlx->rot += 0.05;
	if (mlx->move_up == 1)
		sub_setall_up(mlx);
	if (mlx->move_down == 1)
		sub_setall_down(mlx);
	mlx->y = 0;
	mlx->x = 0;
	mlx->min_k = 0;
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
	if (key == A)
		mlx->move_left = 1;
	if (key == D)
		mlx->move_right = 1;
	if (key == W)
		mlx->move_up = 1;
	if (key == S)
		mlx->move_down = 1;
	if (key == SHIFT)
		mlx->move_sprint = 1;
	if (key == ESC)
		exit(0);
	return (1);
}

int		key_release(int key, t_mlx *mlx)
{
	if (key == A)
		mlx->move_left = 0;
	if (key == D)
		mlx->move_right = 0;
	if (key == W)
		mlx->move_up = 0;
	if (key == S)
		mlx->move_down = 0;
	if (key == SHIFT)
		mlx->move_sprint = 0;
	if (key == ESC)
		exit(0);
	return (1);
}
