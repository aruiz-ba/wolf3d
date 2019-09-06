/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:47:53 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/09/06 16:45:18 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

//1-Leer mapas Y dibujarlos en 2D
//2-Ray casting
//3-Render ray casting

void	set_multythread(t_m *m)
{
	m->y = 0;
	m->x = 0;
	m->min_k = 0;
}

void	set_board(t_m *m)
{
	int x;
	int	out;
	double	angind;
	int	i;
	t_point a;
	t_point b;

	i = 1;
	angind = (((double)60/(double)WIN_WIDTH));
	x = 0;
	while(x < WIN_WIDTH)
	{
		printf("angle:%f\n", ((angind * x) + 60));
		out = raycast((angind * x) + 60);
		printf("out:%i\n", out);
		a.x = x;
		a.y = (WIN_HEIGHT/2) - (out/2);
		b.x = x;
		b.y = (WIN_HEIGHT/2) + (out/2);
		//printf("b.y:%i\n\n", b.y);
		//printf("Point A:i(%i,%i) Point B:(%i,%i)\n", a.x, a.y, b.x, b.y);
		put_line(&a, &b, &m->map);
		x++;
	}
}

int		main(int argc, char **argv)
{
	t_m	*m;

	m = NULL;
	if(argc != 2)
	{
		ft_putstr("not good input\n");
		return(0);
	}
	if (!(m = (t_m*)malloc(sizeof(t_m))))
		return (-1);
	ft_bzero(m, sizeof(m));
	m->mlx.mlx = mlx_init();
	m->mlx.win = mlx_new_window(m->mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "fract");
	new_image(m);
	set_multythread(m);
	//read_file(m);
	set_board(m); //CREO QUE EL PROBLEMA RESIDE EN EL SENO Y COSENO
	raycast(atoi(argv[1]));
	//printf("OUTPUT:%i",raycast(atoi(argv[1])));
	fill_image(m);
	mlx_put_image_to_window(m->mlx.mlx, m->mlx.win, m->img.image, 0, 0);
//	setall(&m->mlx);
	mlx_hook(m->mlx.win, 2, 1L << 2, deal_key, &m->mlx);
	mlx_loop(m->mlx.mlx);
}
