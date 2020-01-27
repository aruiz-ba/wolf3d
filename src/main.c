/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:47:53 by aruiz-ba          #+#    #+#             */
/*   Updated: 2020/01/27 18:35:58 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		error(int i)
{
	ft_putstr("Error: ");
	if (i == 0)
	{
		ft_putstr("Wrong number of spaces or number of values in the map\n");
		ft_putstr("There must be the same number of values on each line\n");
		ft_putstr("Usage:\n* 1 for walls\n* 2 for player\n");
		ft_putstr("* 0 for empty places\n");
		ft_putstr("* Only one space between each value\n");
	}
	if (i == 1)
		ft_putstr("The map border is open\n");
	if (i == 2)
		ft_putstr("No player on map\n");
	if (i == 3)
		ft_putstr("Textures did not load properly\n");
	if (i == 4)
		ft_putstr("Map not found\n");
	exit(0);
}

void		if_error(t_mlx *mlx, t_list *map)
{
	int		er;

	if ((mlx->ry.worldmap = set_board(map, mlx)) == NULL)
		error(0);
	if (test_board(mlx) == 0)
		error(1);
	if ((er = get_player_pos(mlx)) == 0)
		error(2);
}

void		set_mlx(t_mlx *mlx)
{
	mlx->y = 0;
	mlx->x = 0;
	mlx->rot = 0;
	mlx->sprint = 0;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "wolf3d");
	mlx->img.image = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->img.ptr = mlx_get_data_addr(mlx->img.image, &mlx->img.bpp,
			&mlx->img.stride, &mlx->img.endian);
	mlx->spacebar = 1;
}

int			main(void)
{
	t_mlx	mlx;
	t_list	*map;
	int		ln;
	int		dt;

	if (open("map", O_RDONLY | O_NOFOLLOW) == -1)
		error(4);
	if ((map = ft_parse_file("map", &ln, &dt)) == NULL)
		exit(0);
	set_mlx(&mlx);
	if_error(&mlx, map);
	load_textures(&mlx);
	text_to_pixel(&mlx);
	setall(&mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.image, 0, 0);
	mlx_hook(mlx.win, 2, (1L << 0), key_press, &mlx);
	mlx_hook(mlx.win, 3, (1L << 1), key_release, &mlx);
	mlx_hook(mlx.win, 17, 0, close_window, &mlx);
	mlx_loop_hook(mlx.mlx, setall, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
