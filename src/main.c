#include <wolf3d.h>

void set_multythread(t_m *m)
{
	m->y = 0;
	m->x = 0;
	m->min_k = 0;
	m->end_k = (WIN_HEIGHT * WIN_WIDTH) * 4;
}

int	main()
{
	t_m	*m;
	t_point a;
	t_point b;

	m = NULL;
	if (!(m = (t_m*)malloc(sizeof(t_m))))
		return (-1);
	ft_bzero(m, sizeof(m));
	m->mlx.mlx = mlx_init();
	m->mlx.win = mlx_new_window(m->mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "fract");
	new_image(m);
	set_multythread(m);
	a.x = 0;
	a.y = 0;
	b.x = 100;
	b.y = 300;
	put_line(&a, &b, &m->map);
	fill_image(m);
	mlx_put_image_to_window(m->mlx.mlx, m->mlx.win, m->img.image, 0, 0);
	//setall(&m->mlx);
	mlx_hook(m->mlx.win, 2, 1L << 2, deal_key, &m->mlx);
	mlx_loop(m->mlx.mlx);
}
