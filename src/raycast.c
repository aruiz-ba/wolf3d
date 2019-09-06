/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 16:37:23 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/09/06 16:45:16 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int		wall_height(int		dist_wall)
{
	return(((double)64/(double)dist_wall) * 50);
}
Note: remember the Cartesian coordinate is increasing downward (as in page 3), and any fractional values will be rounded down.
int		raycast(double	angle)
{
	int		worldmap[4][4] = 
	{	
		{1, 1, 1, 1},
		{1, 0, 0, 1},
		{0, 0, 0, 1},
		{0, 2, 1, 1}
	};
	t_point	A;
	t_point	P;
	t_point	tm;
	int				Xa;
	int				Ya;
	int				distv;
	int				disth;

	P.y = 224;
	P.x	= 96;
	//if angle is 90
	if(angle > 88 && angle < 92)
	{
		return(50);
	}
	if(angle > 92)
	{
		angle = map1(angle, 60, -90, -120);
	}
	angle = (angle) * M_PI / 180;
	//horizontal lines
	
	A.y = (P.y/64) * (64) - 1;
	A.x = P.x + (P.y - A.y) / tan(angle);
	Ya = -64;//if ray its going up;
	Xa = 64 / tan(angle);
	//printf("GridCoordinate:(%i,%i)\n", A.x/64, A.y/64);
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
		printf("GridCoordinateHorizon:(%d,%i)\n", tm.x/64, tm.y/64);
	}
	else
	{
		printf("GridCoordinateHorizon:(%d,%i)\n", A.x/64, A.y/64);
		disth = abs(P.x - A.x) / cos(angle);
	}
	//Vertical lines

	if(((angle * 180)/ M_PI) == 90)
		return(wall_height(disth * cos(angle)));
	if(((angle * 180)/ M_PI) > 90)
	{
		A.x = (P.x/64) * (64) - 1;
		A.y = P.y + (P.x - A.x) * tan(angle);
			Ya = 64 * tan(angle);//if ray its going up;
		Xa = -64;
	}
	else
	{
		A.x = (P.x/64) * (64) + 64; 
		Xa = 64;
	//	printf("Me estoy corriendo");
	}
	//printf("GridCoordinateVertic:(%i,%i)\n", A.x/64, A.y/64);
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
		printf("GridCoordinateVertitm:(%d,%i)\n", tm.x/64, tm.y/64);
	}
	else
	{
		distv = abs(P.x - A.x) / cos(angle); 
		printf("GridCoordinateVerti:(%d,%i)\n", A.x/64, A.y/64);
	}
	printf("Distance:(v:%i,h:%i)\n", distv, disth);
	if(distv < disth)
	{
		//printf("DISTV:(%i)\n", distv);
		return(wall_height(distv * cos(angle))); //Size corrected to avoid fisheye
	}
	else
	{
		//printf("DISTH:(%i)\n", disth);
		//printf("cosangle:(%f)\n", cos(angle));
		return(wall_height(disth * cos(angle)));
	}
}
//WORKS BUT NOW YOU NEED TO MAKE IT WORK WITH RAYS GROWING POSITIVE AND NEGATIVE AND IF RAYS
//GO LEFT OR RIGHT
//Distance is also broken I think
