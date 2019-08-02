# define FRAC_H
# include "../Libft/libft.h"
# include "mlx.h"
# include "math.h"
# include "pthread.h"
# define WIN_WIDTH	700
# define WIN_HEIGHT	700
# define LEFT		123
# define RIGHT		124
# define ESC		53

typedef struct		s_image
{
	void			*image;
	char			*ptr;
	int				bpp;
	int				stride;
	int				endian;
}					t_image;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	double			a;
	double			b;
	t_image			*img;
}					t_mlx;

typedef struct		s_m
{
	t_mlx			mlx;
	t_image			img;
}					t_m;

int	deal_key(int key, t_mlx *mlx);
void	setall(t_mlx *mlx);
void	new_image(t_m *m);
void	freeimage(char **image_string);
