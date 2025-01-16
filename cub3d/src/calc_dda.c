/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_dda.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdel-f <rabdel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:07:11 by rabdel-f          #+#    #+#             */
/*   Updated: 2025/01/16 12:07:13 by rabdel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

double	get_distance(t_game *g, int less_zero, int is_x)
{
	if (is_x && less_zero)
		return ((g->player.pos.x - g->player.map_square.x) \
			* g->player.delta_dist_x);
	else if (is_x && !less_zero)
		return ((g->player.map_square.x + 1.0 - g->player.pos.x) \
			* g->player.delta_dist_x);
	else if (!is_x && less_zero)
		return ((g->player.pos.y - g->player.map_square.y) \
			* g->player.delta_dist_y);
	else
		return ((g->player.map_square.y + 1.0 - g->player.pos.y) \
			* g->player.delta_dist_y);
}

void	calculate_delta(t_game *g)
{
	g->player.delta_dist_x = fabs(1 / g->player.ray_dir.x);
	g->player.delta_dist_y = fabs(1 / g->player.ray_dir.y);
	if (g->player.ray_dir.x < 0)
	{
		g->player.dist_to_side_x = get_distance(g, YES, YES);
		g->player.step_x = -1;
	}
	else
	{
		g->player.dist_to_side_x = get_distance(g, NO, YES);
		g->player.step_x = 1;
	}
	if (g->player.ray_dir.y < 0)
	{
		g->player.dist_to_side_y = get_distance(g, YES, NO);
		g->player.step_y = -1;
	}
	else
	{
		g->player.dist_to_side_y = get_distance(g, NO, NO);
		g->player.step_y = 1;
	}
}

void	dda(t_game *g)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (g->player.dist_to_side_x < g->player.dist_to_side_y)
		{
			g->player.dist_to_side_x += g->player.delta_dist_x;
			g->player.map_square.x += g->player.step_x;
			g->player.hit_side = 0;
		}
		else
		{
			g->player.dist_to_side_y += g->player.delta_dist_y;
			g->player.map_square.y += g->player.step_y;
			g->player.hit_side = 1;
		}
		if (g->map[g->player.map_square.y][g->player.map_square.x] == '1')
			hit = 1;
	}
}

void	calculate_distance(t_game *g)
{
	t_player	*p;

	p = &g->player;
	if (p->hit_side == 0)
		p->size_ray = perpendicular_dist_x(p, p->step_x);
	else
		p->size_ray = perpendicular_dist_y(p, p->step_y);
}

void	calculate_height_wall(t_game *game)
{
	t_player	*p;

	p = &game->player;
	p->tall_of_wall = fabs(((double)game->game_h / p->size_ray));
	p->tall_of_wall_y1 = (game->game_h / 2.00) - (p->tall_of_wall / 2.00);
	p->tall_of_wall_y2 = (game->game_h / 2.00) + (p->tall_of_wall / 2.00);
	if (p->tall_of_wall_y1 < 0)
		p->tall_of_wall_y1 = 0;
	if (p->tall_of_wall_y2 > game->game_h)
		p->tall_of_wall_y2 = game->game_h -1;
	find_out_text_x(p);
}
// get_distance() function calculates
//the initial distance to the
//first intersection of a ray with 
//either a vertical or horizontal
//grid line. This is a key part of
//the Digital Differential Analysis (DDA) algorithm,
//used in raycasting to determine the 
//points where a ray intersects a 2D grid.
//
// calculate_delta() function is an essential part of
//the raycasting process,
//preparing the data necessary for the Digital
//Differential Analysis (DDA) algorithm. 
//It calculates the distances the ray must travel to
//cross grid lines in the x and y
//directions, as well as the initial distances to the
//nearest grid line. 
//Additionally, it determines the stepping direction
//based on the ray's direction.
//
// dda() function is a critical part of the raycasting
//process in a grid-based 2D game.
//It employs the Digital Differential Analysis (DDA)
//algorithm to trace the path of a ray
//from the player's position through the game map,
//stopping when the ray intersects a wall 
//(represented by the '1' character in the map array).
//
// calculate_distance() determines the 
//distance from the player to the wall
//based on the ray's direction and which side
//(vertical or horizontal) the ray is
//currently colliding with. This is a crucial
//part of raycasting algorithms to calculate
//the precise distance of obstacles (like walls)
//in the player's path.
//
//The function calculates the height of the wall
//segment that corresponds to the current ray.
//This is important for simulating perspective, where 
//closer walls appear taller and farther 
//walls appear shorter.
