/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 14:02:24 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/08/12 18:08:16 by aruiz-ba         ###   ########.fr       */
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

void	fill_image(t_m	*m)
{
	int		bright;
	int		x;
	int		y;

	y = m->y;
	x = m->x;
	bright = 0xFF0000;
	while (m->y < (WIN_WIDTH + y) && m->min_k <= 1960000) //change 1960000 with end_k
	{
		m->x = x;
		while (m->x < (WIN_HEIGHT + x) && m->min_k <= 1960000)
		{
			m->n = 0;
			(m->img.ptr)[m->min_k + 0] = m->map.grid[m->x][m->y] % 256 % 256;
			(m->img.ptr)[m->min_k + 1] = m->map.grid[m->x][m->y] / 256 % 256;
			(m->img.ptr)[m->min_k + 2] = m->map.grid[m->x][m->y] / 256 / 256;
			(m->img.ptr)[m->min_k + 3] = 0;
			m->min_k += 4;
			m->x++;
		}
		m->y++;
	}
}

void	new_image(t_m *m)
{
	m->img.image = mlx_new_image(m->mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	m->img.ptr = mlx_get_data_addr(m->img.image, &m->img.bpp, &m->img.stride,
	&m->img.endian);
}

