/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 14:12:23 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/07/15 17:44:09 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	setall(t_mlx *mlx)
{
	int	i;

	i = -1;
//	freeimage(&mlx->img->ptr);
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->image, 0, 0);
}

int		deal_key(int key, t_mlx *mlx)
{
	if (key == LEFT)
	//	mlx->x -= 50;
	if (key == RIGHT)
	//	mlx->x += 50;
	if (key == ESC)
		exit(0);
	if(key == LEFT)
		setall(mlx);
	return (1);
}
