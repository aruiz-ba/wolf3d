/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:47:53 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/09/12 19:33:21 by aruiz-ba         ###   ########.fr       */
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
/*	
	int	a;
	int b;

	a = 64;
	b = 64;
	mlx.img.image = mlx_xpm_file_to_image(mlx.mlx, "text/wood.xpm", &a, &b);
	mlx.img.ptr = mlx_get_data_addr(mlx.img.image, &mlx.img.bpp, &mlx.img.stride, &mlx.img.endian);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.image, 0, 0);
*/
	//mlx.ry.worldMap = set_board(map);	
	setall(&mlx);
	mlx_hook(mlx.win, 2, 1L << 2, deal_key, &mlx);
	mlx_loop(mlx.mlx);
}
