/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 16:37:23 by aruiz-ba          #+#    #+#             */
/*   Updated: 2019/08/16 16:51:06 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	raycast()
{
	int		worldmap[6][4] = 
	{	
		{1 1 1 1 1 1},
		{1 0 1 0 0 1},
		{0 0 0 0 0 0},
		{0 0 2 0 0 0}
	};
	double	posX = 3;
	double	posY = 4;
	double	dirX = 0;
	double	dirY = 1;
	double	planeX = 0;
	//double	planeY = 0.66;//Field of view?? Check what is this
	
	//loop a partir de aqui
	int		i;

	x = -1;
	while(++x < WIN_WIDTH)
	{
		double	cameraX = 2 * x / double(WIN_WIDTH) - 1;
		double	rayDirX = dirX + planeX * cameraX;
		double	rayDirY = dirY + planeY * cameraX;

		int	mapX = int(posX);
		int mapY = int(posY);

		double sideDistX;
		double sideDistY;

		double deltaDistX 
	}
}

