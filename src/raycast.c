/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 16:37:23 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/08/26 12:31:03 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	raycast()
{
	int		worldmap[4][4] = 
	{	
		{1, 1, 1, 1},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 2, 0, 0}
	};
	//int		grid[320][200];
	t_point	A;
	t_point	P;
	t_point	tm;
	int		Xa;
	int		Ya;
	int		distv;
	int		disth;
	double	angle;

	P.y = 224;
	P.x	= 96;
	angle = 60 *M_PI / 180;
	//horizontal lines
	A.y = (P.y/64) * (64) - 1;
	A.x = P.x + (P.y - A.y) / tan(angle);
	Ya = -64;//if ray its going up;
	Xa = 64 / tan(angle);
	printf("GridCoordinate:(%i,%i)\n", A.x/64, A.y/64);
	if(worldmap[A.x/64][A.y/64] == 0)
	{
		tm.x = A.x;
		tm.y = A.y;
		while(worldmap[tm.y/64][tm.x/64] == 0)
		{
			tm.x += Xa;
			tm.y += Ya;
		}
		disth = abs(P.x - tm.x) / cos(angle);
		printf("GridCoordinate:(%d,%i)\n", tm.x/64, tm.y/64);
	}
	else
		printf("GridCoordinate:(%d,%i)\n", A.x/64, A.y/64);
		disth = abs(P.x - A.x) / cos(angle);
	//Vertical lines
	A.x = (P.x/64) * (64) + 64; //If the ray is facing left (P.x/64) * (64) - 1; 
	A.y = P.y + (P.x - A.x) * tan(angle);
	Ya = -64 * tan(angle);//if ray its going up;
	Xa = 64;
	printf("GridCoordinate:(%i,%i)\n", A.x/64, A.y/64);
	if(worldmap[A.x/64][A.y/64] == 0)
	{
		tm.x = A.x;
		tm.y = A.y;
		while(worldmap[tm.y/64][tm.x/64] == 0)
		{
			tm.x += Xa;
			tm.y += Ya;
		}
		distv = abs(P.x - tm.x) / cos(angle);
		printf("GridCoordinate:(%d,%i)\n", tm.x/64, tm.y/64);
	}
	else
		distv = abs(P.x - A.x) / cos(angle); 
	printf("Distance:(%i,%i)\n", distv, disth);
}
//WORKS BUT NOW YOU NEED TO MAKE IT WORK WITH RAYS GROWING POSITIVE AND NEGATIVE AND IF RAYS
//GO LEFT OR RIGHT
