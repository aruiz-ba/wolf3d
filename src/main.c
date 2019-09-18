/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:47:53 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/09/18 17:07:57 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

//1-Leer mapas Y dibujarlos en 2D
//2-Ray casting
//3-Render ray casting

int		main(int argc, char **argv)
{
	t_mlx mlx;
	//t_list *map;
	//int		ln;
	//int		dt;
	
	if(argc != 2)
		return(0);
	argv = NULL; //borrar
/*	if((map = ft_parse_file(argv[1], &ln, &dt)) == NULL)
		return(0);*/
	mlx.y = 0;
	mlx.x = 0;
	mlx.min_k = 0;
	mlx.rot = 0;
	mlx.posX = 12;
	mlx.posY = 13;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "fract");
	new_image(&mlx);
	//mlx.ry.worldMap = set_board(map);	//CRASHEA POR ALGUN MOTIVO
	load_textures(&mlx);
	//setall(&mlx);
	text_to_pixel(&mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.tex.image, 0, 0);
	mlx_hook(mlx.win, 2, 1L << 2, deal_key, &mlx);
	mlx_loop(mlx.mlx);
}
