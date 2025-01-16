/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_vector1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 08:32:47 by hkheired          #+#    #+#             */
/*   Updated: 2025/01/16 08:32:49 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

t_vector	add_vector(t_vector *v1, t_vector *v2)
{
	t_vector	new;

	new.x = v1->x + v2->x;
	new.y = v1->y + v2->y;
	return (new);
}

t_vector	mult_vector(t_vector *v, double n)
{
	t_vector	new;

	new.x = v->x * n;
	new.y = v->y * n;
	return (new);
}

double	perpendicular_dist_x(t_player *p, int step_x)
{
	double	n;

	n = fabs(p->map_square.x - p->pos.x + ((1 - step_x) / 2));
	n /= p->ray_dir.x;
	return (n);
}

double	perpendicular_dist_y(t_player *p, int step_y)
{
	double	n;

	n = fabs(p->map_square.y - p->pos.y + ((1 - step_y) / 2));
	n /= p->ray_dir.y;
	return (n);
}
// mult_vector() multiplies each component of a vector by a scalar 
//value to produce a scaled version of the vector.
//
// add_vector() to compute the resultant vector by adding two 
//vectors component-wise.
//
//The function perpendicular_dist_x() computes the perpendicular
//distance from the player's current position to the vertical grid
//line that the ray is heading towards. This is often used in 
//raycasting algorithms to calculate the distance from the player
//to the next vertical grid line, ensuring proper rendering of walls.
//
//The function perpendicular_dist_y() computes the perpendicular
//distance from the player's current position to the vertical grid
//line that the ray is heading towards. This is often used in
//raycasting algorithms to calculate the distance from the player to
//the next horizontal grid line, ensuring proper rendering of walls.
