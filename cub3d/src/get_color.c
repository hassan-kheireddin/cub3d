/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 08:32:57 by hkheired          #+#    #+#             */
/*   Updated: 2025/01/16 08:32:59 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static int	obtain_color_pixel(t_data *img,
		int point_x, int point_y)
{
	return (*(int *)(img->addr + (point_y * img->line_len + point_x * \
					(img->bpp / 8))));
}

int	obtain_color(t_game *cub3d)
{
	int	x;
	int	y;

	x = cub3d->player.text_x;
	y = cub3d->player.text_y;
	if (cub3d->player.hit_side)
	{
		if (cub3d->player.pos.y > cub3d->player.map_square.y)
			return (obtain_color_pixel(&cub3d->north_img, x, y));
		else
			return (obtain_color_pixel(&cub3d->south_img, x, y));
	}
	else
	{
		if (cub3d->player.pos.x < cub3d->player.map_square.x)
			return (obtain_color_pixel(&cub3d->east_img, x, y));
		else
			return (obtain_color_pixel(&cub3d->west_img, x, y));
	}
}

void	find_out_text_x(t_player *player)
{
	double	wall;

	if (!player->hit_side)
	{
		if (player->pos.x < player->map_square.x)
			wall = player->pos.y + player->size_ray * player->ray_dir.y;
		else
			wall = player->pos.y - player->size_ray * player->ray_dir.y;
	}
	else
	{
		if (player->pos.y > player->map_square.y)
			wall = player->pos.x - player->size_ray * player->ray_dir.x;
		else
			wall = player->pos.x + player->size_ray * player->ray_dir.x;
	}
	wall -= floor(wall);
	player->text_x = (int)(wall * (double)TEXTURE_SIZE);
	if (player->hit_side && player->pos.y < player->map_square.y)
		player->text_x = TEXTURE_SIZE - player->text_x - 1;
	if (!player->hit_side && player->pos.x > player->map_square.x)
		player->text_x = TEXTURE_SIZE - player->text_x - 1;
}
//find_out_text_x() function determines the horizontal position on
//the texture to use when rendering the wall. This is needed to map
//the correct portion of the texture to the surface of the wall that
//is hit by the ray.
//
// obtain_color_pixel() function fetches the color of a pixel at a
//specific location in an image (based on the x and y coordinates).
//
// obtain_color() function retrieves the correct texture color based
//on the direction the player is facing and the wall they collide with
//(north, south, east, or west).
