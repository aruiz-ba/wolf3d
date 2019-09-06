# define FRAC_H
# include "../Libft/libft.h"
# include "mlx.h"
# include "math.h"
# include "pthread.h"
# include "stdio.h" //BORRAME
# define WIN_WIDTH	640
# define WIN_HEIGHT	400
# define LEFT		123
# define RIGHT		124
# define ESC		53
# define WALL_COLOR	0xFF0000

typedef struct		s_image
{
	void			*image;
	char			*ptr;
	int				bpp;
	int				stride;
	int				endian;
}					t_image;

typedef struct		s_map
{
	unsigned int	grid[WIN_WIDTH][WIN_HEIGHT];
	unsigned int	wallbrd[3][3];
}					t_map;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	double			a;
	double			b;
	t_image			*img;
}					t_mlx;

typedef struct		s_line
{
	int				dy;
	int				dx;
	int				avr;
	int				av;
	int				avi;
	int				xy[2];
	int				inxi;
	int				inyi;
	int				inxr;
	int				inyr;
	int				tmp;
}					t_line;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_rycst
{
	int				proywall;
	int				realwall;
	int				proyPdist;
	int				realPdist;
}					t_rycst;

typedef struct		s_m
{
	t_mlx			mlx;
	t_image			img;
	t_map			map;
	int				x;
	int				y;
	int				min_k;
	int				n;
}					t_m;
int	deal_key(int key, t_mlx *mlx);
void	setall(t_mlx *mlx);
void	new_image(t_m *m);
void	freeimage(char **image_string);
void	fill_image(t_m	*m);
void	set_multythread(t_m *m);
int		put_line(t_point *a, t_point *b, t_map *map);
void	read_file(t_m *m);
int		raycast(double	angle);
double	map1(double a, double a1, double b0, double b1);

