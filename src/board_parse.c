/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:21:11 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/10/16 18:19:40 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		digitnum(char const *s)
{
	int		i;
	int		digitnum;

	i = 0;
	digitnum = 0;
	while (s[i])
	{
		if (s[i] != ' ' && (s[i + 1] == ' ' || s[i + 1] == '\0'))
			digitnum++;
		i++;
	}
	return (digitnum);
}

int		*intrim(char const *s, t_mlx *mlx)
{
	int		i;
	int		digitn;
	int		a;
	int		*array;

	if (!s)
		return (NULL);
	i = 0;
	a = 0;
	digitn = digitnum(s);
	if (!(array = malloc(sizeof(int) * (digitn))))
		return (NULL);
	mlx->ry.mapWidth = digitn;
	while (s[i])
	{
		if (s[i] != ' ' && (s[i + 1] == ' ' || s[i + 1] == '\0'))//protect num more than 1 dig
		{
			if ((s[i] - '0') > 2 || (s[i] - '0') < 0)
				return (NULL);
			array[a] = s[i] - '0';
			a++;
		}
		else if (s[i] != ' ' && s[i + 1] != ' ')
			return (NULL);
		else if (s[i] == ' ' && s[i + 1] == ' ')
			return (NULL);
		i++;
	}
	return (array);
}

int		linked_list_len(t_list *ls)
{
	int		out;
	t_list	*next;
	t_list	*tm;

	out = 0;
	tm = ls;
	while (tm != NULL)
	{
		next = tm->next;
		tm = next;
		out++;
	}
	return (out);
}

int		write_board(int **out, t_list *ls, t_mlx *mlx)
{
	t_list	*tm;
	int		i;

	tm = ls;
	i = 0;
	while (tm != NULL)
	{
		if ((out[i] = intrim(tm->content, mlx)) == NULL)
			return (0);
		tm = tm->next;
		i++;
	}
	return (1);
}

int		**set_board(t_list *ls, t_mlx *mlx)
{
	int		**out;
	int		height;

	height = linked_list_len(ls);
	if ((out = malloc(sizeof(int*) * height)) == NULL)
		exit(0);
	mlx->ry.mapHeight = height;
	if (write_board(out, ls, mlx) == 0)
		return (NULL);
	return (out);
}
