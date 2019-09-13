/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:11:23 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/09/13 20:32:21 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	load_textures(t_mlx	*mlx)
{
	int		a;
	int		b;

	a = 64;
	b = 64;
	mlx->tex.image = mlx_xpm_file_to_image(mlx->mlx, "textures/wood.xpm", &a, &b);
	mlx->tex.ptr = mlx_get_data_addr(mlx->tex.image, &mlx->tex.bpp,
			&mlx->tex.stride, &mlx->tex.endian);
}
