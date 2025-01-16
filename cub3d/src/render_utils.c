/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdel-f <rabdel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:07:45 by rabdel-f          #+#    #+#             */
/*   Updated: 2025/01/16 12:07:49 by rabdel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	map_position_square(t_player *player)
{
	player->map_square.x = floor(player->pos.x);
	player->map_square.y = floor(player->pos.y);
}

void	my_mlx_pixel_put(t_game *cub3d, int x, int y, int color)
{
	char	*dst;

	dst = cub3d->frame.addr + (y * cub3d->frame.line_len + x \
		* (cub3d->frame.bpp / 8));
	*(unsigned int *)dst = color;
}

inline static int	create_floor(t_game *g)
{
	int	x;
	int	y;

	y = g->game_h / 2;
	while (y < g->game_h)
	{
		x = 0;
		while (x < g->game_w)
		{
			my_mlx_pixel_put(g, x, y, g->floor);
			x++;
		}
		y++;
	}
	return (0);
}

static inline int	create_ceiling(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (y < g->game_h)
	{
		x = 0;
		while (x < g->game_w)
		{
			my_mlx_pixel_put(g, x, y, g->ceiling);
			x++;
		}
		y++;
	}
	return (0);
}

int	create_background(t_game *g)
{
	create_ceiling(g);
	create_floor(g);
	return (0);
}
// create_floor() Fills the bottom half of the frame with
//the floor color, Starts at the middle of the game height
//(y = g->game_h / 2) and iterates through each pixel in the
//lower half of the frame (y < g->game_h). For each row, iterates
//through all columns (x < g->game_w). lets the pixel color
//at (x, y) to the floor color using the helper function my_mlx_pixel_put.
//
// create_ceiling() Fills the top half of the frame with the ceiling
//color. Starts from the top of the frame (y = 0) and iterates
//through each pixel in the upper half of the frame (y < g->game_h / 2).
//For each row, iterates through all columns (x < g->game_w). Sets the
//pixel color at (x, y) to the ceiling color using the same helper function.
//
//create_background() Combines create_ceiling and create_floor to fill the
//entire frame with the ceiling and floor colors.
//
// my_mlx_pixel_put() function writes a specific color to a pixel at 
//position (x, y) in the cub3d->frame image. This function is a low-level
//utility used in graphics programming to directly manipulate pixel data
//in an image buffer.
//
//The map_position_square function calculates the player's current position
//on a grid-based map by mapping their precise position (x, y) to the
//nearest integer "square" coordinates.