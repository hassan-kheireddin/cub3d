/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 08:33:01 by hkheired          #+#    #+#             */
/*   Updated: 2025/01/16 08:33:03 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	move_positionx(t_game *game, t_vector *dir, int direction)
{
	t_player	*p;
	t_vector	temp;

	temp.x = dir->x;
	temp.y = dir->y;
	rotate_vector(&temp, PI / 2);
	p = &game->player;
	p->pos.y += MOV * temp.y * direction;
	p->pos.x += MOV * temp.x * direction;
	if (game->map[(int)p->pos.y][(int)p->pos.x] != '0')
	{
		p->pos.y -= MOV * temp.y * direction;
		p->pos.x -= MOV * temp.x * direction;
		return ;
	}
	rayscasting(game);
}

void	move_positiony(t_game *game, t_vector *dir, int direction)
{
	t_player	*p;

	p = &game->player;
	p->pos.y += MOV * dir->y * direction;
	p->pos.x += MOV * dir->x * direction;
	if (game->map[(int)p->pos.y][(int)p->pos.x] != '0')
	{
		p->pos.y -= MOV * dir->y * direction;
		p->pos.x -= MOV * dir->x * direction;
		return ;
	}
	rayscasting(game);
}

void	rotate_left(t_game *game)
{
	t_player	*p;
	double		olddirx;
	double		oldplanex;

	p = &game->player;
	olddirx = p->dir.x;
	p->dir.x = p->dir.x * cos(ROT) - p->dir.y * sin(-ROT);
	p->dir.y = olddirx * sin(-ROT) + p->dir.y * cos(-ROT);
	oldplanex = p->plane.x;
	p->plane.x = p->plane.x * cos(-ROT) - p->plane.y * sin(-ROT);
	p->plane.y = oldplanex * sin(-ROT) + p->plane.y * cos(-ROT);
	rayscasting(game);
}

void	rotate_right(t_game *game)
{
	t_player	*p;
	double		olddirx;
	double		oldplanex;

	p = &game->player;
	olddirx = p->dir.x;
	p->dir.x = p->dir.x * cos(ROT) - p->dir.y * sin(ROT);
	p->dir.y = olddirx * sin(ROT) + p->dir.y * cos(ROT);
	oldplanex = p->plane.x;
	p->plane.x = p->plane.x * cos(ROT) - p->plane.y * sin(ROT);
	p->plane.y = oldplanex * sin(ROT) + p->plane.y * cos(ROT);
	rayscasting(game);
}

int	read_keys(int keypress, t_game *game)
{
	if (keypress == KEY_ESC)
		end_game(game);
	if (keypress == W)
		move_positiony(game, &game->player.dir, 1);
	if (keypress == S)
		move_positiony(game, &game->player.dir, -1);
	if (keypress == A)
		move_positionx(game, &game->player.dir, -1);
	if (keypress == D)
		move_positionx(game, &game->player.dir, 1);
	if (keypress == LEFT)
		rotate_left(game);
	if (keypress == RIGHT)
		rotate_right(game);
	return (0);
}
// move_positiony() function moves the player in the Y
//direction and updates their position accordingly. If
//the new position would result in a collision (the player
//moves into a non-empty space like a wall), it will revert
//to the original position and not update the player's
//coordinates. If the movement is valid, it proceeds with
//raycasting for rendering the new view.
//
// move_positionx() function allows the player to move in the X direction
//relative to their current orientation by modifying the x
//and y position. It checks for collisions and reverts the
//movement if the new position is blocked (i.e., not a valid
//space). If the movement is valid, the function proceeds with
//raycasting to update the game's visuals.
//
// rotate_left() function is to rotate the player's direction and viewplane
//to simulate turning the player left in the game. It uses basic 2D rotation
//transformations applied to both the player's direction vector (dir) and
//their view plane vector (plane). After applying the transformations, it 
//calls rayscasting to update the game world with the new orientation.
//
// rotate_right() it rotates the player and their viewplane to the right
//(clockwise) instead of left.
//
//The read_keys function is responsible for handling key press events
//in your game and reacting to them accordingly.