#include <wolf3d.h>

//1-Leer mapas Y dibujarlos en 2D
//2-Ray casting
//3-Render ray casting

void	set_multythread(t_m *m)
{
	m->y = 0;
	m->x = 0;
	m->min_k = 0;
	m->end_k = (WIN_HEIGHT * WIN_WIDTH) * 4;
}

void	set_board(t_m *m)
{
	int y;
	int x;
	t_point a;
	t_point b;

	y = 50;
	x = 50;
	while(y < WIN_WIDTH - 100)
	{
		a.x = x;
		a.y = y;
		b.x = WIN_WIDTH - 150;
		b.y = y;
		y += 200;
		put_line(&a, &b, &m->map);
	}
	y = WIN_WIDTH;
	put_line(&a, &b, &m->map);
	y = 50;
	while(x < WIN_HEIGHT - 100)
	{
		a.x = x;
		a.y = y;
		b.x = x;
		b.y = WIN_HEIGHT - 150;
		x += 200;
		put_line(&a, &b, &m->map);
	}
}

int		main()
{
	t_m	*m;

	m = NULL;
	if (!(m = (t_m*)malloc(sizeof(t_m))))
		return (-1);
	ft_bzero(m, sizeof(m));
	m->mlx.mlx = mlx_init();
	m->mlx.win = mlx_new_window(m->mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "fract");
	new_image(m);
	set_multythread(m);
	//read_file(m);
	set_board(m);
	fill_image(m);
	mlx_put_image_to_window(m->mlx.mlx, m->mlx.win, m->img.image, 0, 0);
	//setall(&m->mlx);
	raycast();
	mlx_hook(m->mlx.win, 2, 1L << 2, deal_key, &m->mlx);
	mlx_loop(m->mlx.mlx);
}
