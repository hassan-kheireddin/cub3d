/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 08:33:37 by hkheired          #+#    #+#             */
/*   Updated: 2025/01/16 08:33:38 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	rotate_vector(t_vector *v, double angle)
{
	double	x;
	double	y;

	x = v->x;
	y = v->y;
	v->x = x * cos(angle) - y * sin(angle);
	v->y = x * sin(angle) + y * cos(angle);
}

void	set_direction(t_game *cub3d)
{
	if (cub3d->spawn == 'S')
	{
		cub3d->player.dir.y = ONE;
		cub3d->player.plane.x = -PLANE;
	}
	else if (cub3d->spawn == 'E')
	{
		cub3d->player.dir.x = ONE;
		cub3d->player.dir.y = ZERO;
		cub3d->player.plane.x = ZERO;
		cub3d->player.plane.y = PLANE;
	}
	else if (cub3d->spawn == 'W')
	{
		cub3d->player.dir.x = -ONE;
		cub3d->player.dir.y = ZERO;
		cub3d->player.plane.x = ZERO;
		cub3d->player.plane.y = -PLANE;
	}
}

void	set_player_position(t_game *cub3d, int i, int j)
{
	while (cub3d->map[++i])
	{
		j = -1;
		while (cub3d->map[i][++j])
		{
			if (cub3d->map[i][j] == cub3d->spawn)
			{
				cub3d->player.pos.x = j + 0.5;
				cub3d->player.pos.y = i + 0.5;
				cub3d->map[i][j] = '0';
				set_direction(cub3d);
				return ;
			}
		}
	}
}
//set_player_position function is responsible for
//determining the initial position of the player in
//the game world and updating the player's attributes
//accordingly.
//
//The set_direction function configures the player's
//initial direction and camera plane based on the spawn
//orientation ('S', 'E', 'W').
//
//his function effectively rotates the vector v by the
//specified angle (in radians), updating the vector
//components in-place. This can be useful for rotating
//directions, player movement vectors, or any other 2D
//vector in the game or graphical system.