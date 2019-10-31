/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:21:11 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/10/31 15:19:16 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		sub_intrim(t_intrim *in, char const *s)
{
	if (s[in->i] != ' ' && (s[in->i + 1] == ' ' || s[in->i + 1] == '\0'))
	{
		if ((s[in->i] - '0') > 2 || (s[in->i] - '0') < 0)
			return (-1);
		in->array[in->a] = s[in->i] - '0';
		in->a++;
	}
	else if (s[in->i] != ' ' && s[in->i + 1] != ' ')
		return (-1);
	else if (s[in->i] == ' ' && s[in->i + 1] == ' ')
		return (-1);
	return (1);
}

int		*intrim(char const *s, t_mlx *mlx)
{
	t_intrim	in;

	in.a = 0;
	if (!s)
		return (NULL);
	in.i = 0;
	in.a = 0;
	in.digitn = digitnum(s);
	if (!(in.array = malloc(sizeof(int) * (in.digitn))))
		return (NULL);
	mlx->ry.mapwidth = in.digitn;
	while (s[in.i])
	{
		if (sub_intrim(&in, s) == -1)
			return (NULL);
		in.i++;
	}
	return (in.array);
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
	mlx->ry.mapheight = height;
	if (write_board(out, ls, mlx) == 0)
		return (NULL);
	return (out);
}
