/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:19:37 by aruiz-ba          #+#    #+#             */
/*   Updated: 2020/01/27 16:08:45 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "../Libft/libft.h"
# include "mlx.h"
# include "math.h"
# include "fcntl.h"
# define WIN_WIDTH	1080
# define WIN_HEIGHT	720
# define TEXWIDTH 	64
# define TEXHEIGHT	64
# define P_SPEED	0.05
# define SPACEBAR	49
# define SHIFT		257
# define ESC		53
# define RGB_RED	0xFF0000
# define RGB_GREEN	0x00FF00
# define RGB_BLUE	0x0000FF
# define RGB_WHITE	0xFFFFFF
# define RGB_YELLOW	0xFFFF00

typedef struct		s_parse
{
	int				fd;
	int				wrds;
	char			*buff;
	int				ret;
}					t_parse;

typedef struct		s_image
{
	void			*image;
	char			*ptr;
	int				bpp;
	int				stride;
	int				endian;
	int				pix[64][64];
}					t_image;

typedef struct		s_skyimg
{
	void			*image;
	char			*ptr;
	int				bpp;
	int				stride;
	int				endian;
	int				pix[1080][720];
}					t_skyimg;

typedef struct		s_map
{
	unsigned int	grid[WIN_WIDTH][WIN_HEIGHT];
	int				color;
}					t_map;

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
	double			x;
	double			y;
}					t_point;

typedef struct		s_intrim
{
	int				i;
	int				digitn;
	int				*array;
	int				a;
}					t_intrim;

typedef struct		s_rycst
{
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	int				**worldmap;
	int				mapheight;
	int				mapwidth;
	int				lineheight;
	int				texx;
	int				x;
	int				side;
	double			wallx;
	int				wallh;
	int				stepx;
	int				stepy;
}					t_rycst;

typedef struct		s_map2
{
	double			a;
	double			a0;
	double			a1;
	double			b0;
	double			b1;
}					t_map2;

typedef struct		s_rycst_loop
{
	int				x;
	int				hit;
	int				mapx;
	int				mapy;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				texx;
	double			sidedistx;
	double			sidedisty;
	double			perpwalldist;
	double			camerax;
	double			raydirx;
	double			raydiry;
	double			deltadistx;
	double			deltadisty;
	double			wallx;
}					t_rycst_loop;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	double			a;
	double			b;
	int				x;
	int				y;
	double			rot;
	double			posx;
	double			posy;
	double			sprint;
	t_image			img;
	t_image			tex[4];
	t_skyimg		skyimg;
	t_map			map;
	t_rycst			ry;
	t_rycst_loop	rl;
	int				move_up;
	int				move_down;
	int				move_right;
	int				move_left;
	int				move_sprint;
	int				spacebar;
}					t_mlx;

int					deal_key(int key, t_mlx *mlx);
int					setall(t_mlx *mlx);
void				new_image(t_mlx *mlx);
void				freeimage(char **image_string);
void				fill_image(t_mlx	*mlx);
void				set_multythread(t_mlx *mlx);
void				put_line(int x, int start, int end, t_mlx *mlx);
void				raycast(t_mlx	*mlx);
double				map1(double a, double a1, double b0, double b1);
double				map2(t_map2 *mp);
void				freegrid(t_map *map);
t_list				*reverse(t_list *head);
t_list				*ft_parse_file(char *root, int *ln, int *dt);
int					**set_board(t_list *ls, t_mlx *mlx);
void				load_textures(t_mlx	*mlx);
void				text_to_pixel(t_mlx *mlx);
int					key_press(int key, t_mlx *mlx);
int					key_release(int key, t_mlx *mlx);
int					test_board(t_mlx *mlx);
int					get_player_pos(t_mlx *mlx);
int					digitnum(char const *s);
void				set_putline_var(t_mlx *mlx);
int					close_window(void *param);
void				error(int i);
#endif
