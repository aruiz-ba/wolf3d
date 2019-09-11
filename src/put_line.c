
#include "wolf3d.h"

void	ifels(t_line *ln)
{
	if (ln->dx >= 0)
		ln->inxi = 1;
	else
	{
		ln->dx = -ln->dx;
		ln->inyi = -1;
	}
	if (ln->dx >= ln->dy)
	{
		ln->inyr = 0;
		ln->inxr = ln->inxi;
	}
	else
	{
		ln->inxr = 0;
		ln->inyr = ln->inyi;
		ln->tmp = ln->dx;
		ln->dx = ln->dy;
		ln->dy = ln->tmp;
	}
}

void	sub_put_line(t_line *ln, t_point *a, t_point *b, t_map *map)
{
	ln->xy[0] = a->x;
	ln->xy[1] = a->y;
	ln->avr = (2 * ln->dy);
	ln->av = (ln->avr - ln->dx);
	ln->avi = (ln->av - ln->dx);
	while (ln->xy[0] != b->x || ln->xy[1] != b->y)
	{
		if ((ln->xy[0] >= 0 && ln->xy[0] <= WIN_WIDTH) &&
		(ln->xy[1] >= 0 && ln->xy[1] <= WIN_HEIGHT))
			map->grid[ln->xy[0]][ln->xy[1]] = map->color;
		if (ln->av >= 0)
		{
			ln->xy[0] = (ln->xy[0] + ln->inxi);
			ln->xy[1] = (ln->xy[1] + ln->inyi);
			ln->av = (ln->av + ln->avi);
		}
		else
		{
			ln->xy[0] = (ln->xy[0] + ln->inxr);
			ln->xy[1] = (ln->xy[1] + ln->inyr);
			ln->av = (ln->av + ln->avr);
		}
	}
}

int		put_line(t_point *a, t_point *b, t_map *map)
{
	t_line ln;

	ln.dy = (b->y - a->y);
	ln.dx = (b->x - a->x);
	if (ln.dy >= 0)
		ln.inyi = 1;
	else
	{
		ln.dy = -ln.dy;
		ln.inyi = -1;
	}
	ifels(&ln);
	sub_put_line(&ln, a, b, map);
	return (0);
}
