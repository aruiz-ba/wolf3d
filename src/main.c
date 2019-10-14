/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:47:53 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/10/14 19:21:16 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	error(int	i)
{
	if (i == 0)	
		ft_putstr("The map border is openi\n");
	if (i == 1)
		ft_putstr("No player on map\n");
	if (i == 2)
		ft_putstr("Not valid map number. Use only 1 for walls and 2 for P pos\n");
	exit(0);
}

int		main(int argc, char **argv)
{
	t_mlx mlx;
	t_list *map;
	int		ln;
	int		dt;
	int		er;

	if (argc != 2)
		return (0);
	if ((map = ft_parse_file(argv[1], &ln, &dt)) == NULL)
		return (0);
	mlx.y = 0;
	mlx.x = 0;
	mlx.min_k = 0;
	mlx.rot = 0;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "wolf3d");
	new_image(&mlx);
	mlx.ry.worldMap = set_board(map, &mlx);
	if (test_board(&mlx) == 0)
		error(0);
	if ((er = get_player_pos(&mlx)) == 0)
		error(1);
	if (er == -1)
		error(2);
	load_textures(&mlx);
	text_to_pixel(&mlx);
	setall(&mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.image, 0, 0);
	mlx_hook(mlx.win, 2, (1L << 0), key_press, &mlx);
	mlx_hook(mlx.win, 3, (1L << 1), key_release, &mlx);
	mlx_loop(mlx.mlx);
}
