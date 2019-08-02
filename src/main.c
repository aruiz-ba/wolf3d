#include <wolf3d.h>

int	main()
{
	t_m	*m;

	m = NULL;
	if (!(m = (t_m*)malloc(sizeof(t_m))))
		return (-1);
	ft_bzero(m, sizeof(m));
	m->mlx.mlx = mlx_init();
	m->mlx.win = mlx_new_window(m->mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "fract");
	new_image(m);
	mlx_put_image_to_window(m->mlx.mlx, m->mlx.win, m->img.image, 0, 0);
//	setall(&m->mlx);
//	mlx_hook(m->mlx.win, 2, 1L << 2, deal_key, &m->mlx);
}
