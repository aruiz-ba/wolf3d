# define FRAC_H
# include "../Libft/libft.h"
# include "mlx.h"
# include "math.h"
# include "pthread.h"
# include "fcntl.h"
# include "stdio.h" //BORRAME
# define WIN_WIDTH	1080//640
# define WIN_HEIGHT	720//400
# define texWidth 	64
# define texHeight	64
# define P_SPEED	0.05
# define W			13
# define S			1
# define A			0
# define D			2
# define SHIFT			257
# define ESC		53
# define RGB_Red	0xFF0000
# define RGB_Green	0x00FF00
# define RGB_Blue	0x0000FF
# define RGB_White	0xFFFFFF
# define RGB_Yellow	0xFFFF00
# define texWidth 64
# define texHeight 64

typedef struct		s_parse
{
	int			fd;
	int			wrds;
	char			*buff;
	int			ret;
}				t_parse;

typedef struct		s_image
{
	void			*image;
	char			*ptr;
	int			bpp;
	int			stride;
	int			endian;
	int		 	pix[64][64];
}				t_image;

typedef struct		s_map
{
	unsigned int		grid[WIN_WIDTH][WIN_HEIGHT];
	int			color;
}					t_map;

typedef struct		s_line
{
	int			dy;
	int			dx;
	int			avr;
	int			av;
	int			avi;
	int			xy[2];
	int			inxi;
	int			inyi;
	int			inxr;
	int			inyr;
	int			tmp;
}				t_line;

typedef struct		s_point
{
	double			x;
	double			y;
}					t_point;

typedef struct			s_intrim
{
	int			i;
	int			digitn;
	int			*array;
	int			a;
}				t_intrim;

typedef struct		s_rycst
{
	double			posX;
	double			posY;
	double			dirX;
	double			dirY;
	double			planeX;
	double			planeY;
	int			**worldMap;
	int			mapHeight;
	int			mapWidth;
	int			lineHeight;
	int			texX;
	int			x;
	int			side;
	double			wallX;
	int			wallh;
	int			stepX;
	int			stepY;
}				t_rycst;

typedef struct			s_map2
{
	double			a;
	double			a0;
	double			a1;
	double			b0;
	double			b1;
}				t_map2;

typedef struct			s_mlx
{
	void			*mlx;
	void			*win;
	double			a;
	double			b;
	int			x;
	int			y;
	int			min_k;
	double			rot;
	double			posX;
	double			posY;
	double			sprint;
	t_image			img;
	t_image			tex[4];
	t_map			map;
	t_rycst			ry;
	int			move_up;
	int			move_down;
	int			move_right;
	int			move_left;
	int			move_sprint;
}				t_mlx;
int	deal_key(int key, t_mlx *mlx);
int	setall(t_mlx *mlx);
void	new_image(t_mlx *mlx);
void	freeimage(char **image_string);
void	fill_image(t_mlx	*mlx);
void	set_multythread(t_mlx *mlx);
void	put_line(int x, int start, int end, t_mlx *mlx);
void	raycast(t_mlx	*mlx);
double	map1(double a, double a1, double b0, double b1);
double	map2(t_map2 *mp);
void	freegrid(t_map *map);
t_list	*reverse(t_list *head);
t_list	*ft_parse_file(char *root, int *ln, int *dt);
int	**set_board(t_list *ls, t_mlx *mlx);
void	load_textures(t_mlx	*mlx);
void	text_to_pixel(t_mlx *mlx);
void	fill_image_texture(t_mlx	*mlx);
int	key_press(int key, t_mlx *mlx);
int	key_release(int key, t_mlx *mlx);
int	test_board(t_mlx *mlx);
int	get_player_pos(t_mlx *mlx);
int	digitnum(char const *s);
