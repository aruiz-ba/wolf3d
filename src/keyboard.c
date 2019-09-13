/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 14:12:23 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/09/13 20:32:14 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>


void	setall(t_mlx *mlx)
{
	mlx->y = 0;
	mlx->x = 0;
	mlx->min_k = 0;
	freeimage(&mlx->img.ptr);
	freegrid(&mlx->map);
	mlx_clear_window(mlx->mlx, mlx->win);
	raycast(mlx);
	fill_image(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.image, 0, 0);
}

int		deal_key(int key, t_mlx *mlx)
{
	if (key == A)
	{
		mlx->rot += 0.04;
		setall(mlx);
	}
	if (key == D)
	{
		mlx->rot -= 0.04;
		setall(mlx);
	}
	if (key == W)
	{
		mlx->posY += mlx->ry.dirY * P_SPEED;
		mlx->posX += mlx->ry.dirX * P_SPEED;
		setall(mlx);
	}
	if (key == S)
	{
		mlx->posY -= mlx->ry.dirY * P_SPEED;
		mlx->posX -= mlx->ry.dirX * P_SPEED;
		setall(mlx);
	}
	if (key == ESC)
		exit(0);
	return (1);
}
