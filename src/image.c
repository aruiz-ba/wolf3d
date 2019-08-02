/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 14:02:24 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/07/15 14:36:33 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	freeimage(char **image_string)
{
	int		i;
	int		k;
	int		color;

	color = 0xFFFFFF;
	k = 0;
	i = 0;
	while (i < (WIN_HEIGHT * WIN_WIDTH))
	{
		(*image_string)[k + 0] = (char)(color % 256 % 256);
		(*image_string)[k + 1] = (char)(color / 256 % 256);
		(*image_string)[k + 2] = (char)(color / 256 / 256);
		(*image_string)[k + 3] = 0;
		k += 4;
		i++;
	}
}
/*
void	fill_image(t_thr *thr, int (*f)(int, t_thr *))
{
	int		bright;
	int		x;
	int		y;

	y = thr->y;
	x = thr->x;
	while (thr->y < (WIN_WIDTH + y) && thr->min_k <= thr->end_k)
	{
		thr->x = x;
		while (thr->x < (WIN_HEIGHT + x) && thr->min_k <= thr->end_k)
		{
			bright = f(bright, thr);
			thr->n = 0;
			(*thr->image_string)[thr->min_k + 0] = bright % 256 % 256;
			(*thr->image_string)[thr->min_k + 1] = bright / 256 % 256;
			(*thr->image_string)[thr->min_k + 2] = bright / 256 / 256;
			(*thr->image_string)[thr->min_k + 3] = 0;
			thr->min_k += 4;
			thr->x++;
		}
		thr->y++;
	}
}
*/
void	new_image(t_m *m)
{
	m->img.image = mlx_new_image(m->mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	m->img.ptr = mlx_get_data_addr(m->img.image, &m->img.bpp, &m->img.stride,
	&m->img.endian);
}

